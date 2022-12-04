ifconfig -a | grep '\<ether\>' | sed  -e $'s/\tether //g' | tr -d " "
