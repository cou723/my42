#!/bin/bash
if [ -n "$1" ]; then
	if [ -e "$1_debug.c" ]; then
		cat ./$1_debug.c | grep -v "printf" | grep -v "stdio.h" >./$1.c
		# 関数の型の後のスペースをtabに置換
		cat ./$1.c | sed -e $"s:^char  :char\t:" -e $"s:^void  :void\t:" -e $"s:^int\t  :int\t\t:" |
			cat ./$1.c | sed -e $"s:^int\t  :int\t\t:" |
			cat ./$1.c | sed -e $"s:^char :char\t:" -e $"s:^void :void\t:" -e $"s:^int :int\t:" |
			# 変数の型の後のスペースをtabに置換
			cat ./$1.c | sed -e $"s:^\tchar :\tchar\t:" -e $"s:^\tvoid :\tvoid\t:" -e $"s:^\tint :\tint\t:" -e $"s:^\tint\t :\tint\t\t:" >./$1.c
	else
		echo "$1_debug.c is not exits"
	fi
else
	echo "arg error"
fi
