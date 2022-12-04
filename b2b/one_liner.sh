## running before connect ssh
sed -i 's/#Port 22/Port 4242/g' /etc/ssh/sshd_config
/etc/init.d/ssh restart
## pre
su
## apt install
apt-get update && apt upgrade && apt -y install fish sudo libpam-pwquality ufw net-tools && chsh -s /usr/bin/fish

## ssh ##
sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin no/g' /etc/ssh/sshd_config

## sudo ##
#apt install sudo
chmod 770 /etc/sudoers && sed -i '12 i Defaults\tpasswd_tries=3' /etc/sudoers && sed -i '13 i Defaults\tbadpass_message="<<<_YOUR_PASSWORD_IS_WRONG!!!!_>>>"' /etc/sudoers && sed -i '14 i Defaults\tiolog_dir="/var/log/sudo"' /etc/sudoers && sed -i '15 i Defaults\trequiretty' /etc/sudoers && sed -i '16 i Defaults\tlog_input' /etc/sudoers && sed -i '17 i Defaults\tlog_output' /etc/sudoers && chmod 440 /etc/sudoers
## password ##
#sudo apt -y install libpam-pwquality
sed -i 's/PASS_MAX_DAYS\t99999/PASS_MAX_DAYS\t30/g' /etc/login.defs && sed -i 's/PASS_MIN_DAYS\t0/PASS_MIN_DAYS\t2/g' /etc/login.defs && sed -i 's/# difok = 1/difok = 7/g' /etc/security/pwquality.conf && sed -i 's/# minlen = 8/minlen = 10/g' /etc/security/pwquality.conf && sed -i 's/# maxrepeat = 0/maxrepeat = 2/g' /etc/security/pwquality.conf && sed -i 's/# ucredit = 0/ucredit = -1/g' /etc/security/pwquality.conf && sed -i 's/# dcredit = 0/dcredit = -1/g' /etc/security/pwquality.conf && sed -i 's/# usercheck = 1/usercheck = 1/g' /etc/security/pwquality.conf && sed -i 's/# enforce_for_loot/enforce_for_loot/g' /etc/security/pwquality.conf
## group ##
sudo groupadd user42 && gpasswd -a xxxxxxx42 user42 && gpasswd -a xxxxxxx42 sudo
## ufw ##
#sudo apt install ufw
sudo ufw default deny incoming && sudo ufw default allow outgoing && sudo ufw allow ssh && sudo ufw allow 4242 && sudo ufw delete 1 && sudo ufw delete 2 && sudo ufw enable

## <powershell>
## sendmoni.bat
## <powershell>

## monitoring.sh
chmod 777 /home/xxxxxxx42/monitoring.sh && mv /home/xxxxxxx42/monitoring.sh /usr/local/bin/monitoring.sh && echo "*/10 * * * * /usr/local/bin/monitoring.sh | wall" >>/var/spool/cron/crontabs/root && sudo systemctl restart cron
