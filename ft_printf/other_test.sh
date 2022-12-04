#!/bin/bash

rm diff.txt pf.txt ft.txt pf.out ft.out
gcc -Wall -Werror -Wextra -D PRINT="printf" main_42tester.c ./libftprintf.a  -o pf.out
gcc -D PRINT="ft_printf" main_42tester.c ./libftprintf.a -o ft.out -g
./pf.out >> pf.txt
./ft.out >> ft.txt
diff ft.txt pf.txt >> diff.txt
