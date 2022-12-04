cat /etc/passwd | sed '/^#/d' | awk '(NR%2==0){print}' | rev | awk -F ":" '{print $NF}' | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' ',' | sed -e "s/,\$/.\$/" | tr -d '\n'
