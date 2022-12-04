find . -name "*\.sh" -type f | sed -e "s/\.\///" -e "s/\.sh//" | sed 's!^.*/!!'
