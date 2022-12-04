find . | grep ft | while read line
do
	grep printf ${line}
done

find . | grep ft | while read line
do
	grep puts ${line}
done
