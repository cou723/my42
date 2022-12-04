#!/bin/bash
echo -n "#Architecture: "
uname -a
echo -n "#CPU physical : "
grep physical.id /proc/cpuinfo | sort -u | wc -l

echo -n "#vCPU : "
grep processor /proc/cpuinfo | wc -l

total_ram=$(free -m | awk '$1 == "Mem:" {print $2}')
used_ram=$(free -m | awk '$1 == "Mem:" {print $3}')
percent_ram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
echo "#Memory Usage: $used_ram/$total_ram MB ($percent_ram%)"

total_disk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
used_disk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
percent_disk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
echo "#Disk Usage: $used_disk/$total_disk Gb ($percent_disk%)"

echo -n "#CPU load: "
top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%\n"), $1 + $3}'
echo -n "#Last boot: "
who -b | sed -e 's/system boot//g' | xargs

echo -n "#LVM use: "
if lsblk | grep -q lvm; then
    echo yes
else
    echo no
fi

echo -n "#Connection TCP : "
echo -n $(cat /proc/net/sockstat{,6} | awk '$1 == "TCP:" {print $3}')
echo " ESTABLISHED"

echo -n "#User log: "
echo $(users | wc -w)

echo -n "#Network: IP "
echo -n $(hostname -I)
echo -n "("
echo -n $(ip addr | awk '$1 == "link/ether" {print $2}')
echo ")"

echo -n "#Sudo : "
echo -n $(journalctl _COMM="sudo" | grep COMMAND | wc -l)
echo " cmd"
