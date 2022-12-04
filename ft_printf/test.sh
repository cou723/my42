./test >output
ESC=$(printf '\033')
sed -n 1P ./output >output2
sed -n 2P ./output >output1
DIFF=$(diff -q output1 output2)
if [ "$DIFF" = "" ]; then
	echo -n "EXPECT: "
	cat output1
	echo -n "ACTUAL: "
	cat output2
	printf "${ESC}[32m%s${ESC}[m" "TEST ALL PASSED"
	echo
else
	echo -n "EXPECT: "
	cat output1
	echo -n "ACTUAL: "
	cat output2
	diff output1 output2
fi
rm output output1 output2
