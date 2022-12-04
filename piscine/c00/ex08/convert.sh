#!/bin/bash
cat ./ft_print_combn_koki_debug.c | grep -v "printf" | grep -v "stdio.h" > ./ft_print_combn_koki.c
cat ./ft_print_combn_koki.c | sed -e $"s:^char  :char\t:" -e $"s:^void  :void\t:" -e $"s:^int\t  :int\t\t:"> ./ft_print_combn_koki.c
cat ./ft_print_combn_koki.c | sed -e $"s:^int\t  :int\t\t:"> ./ft_print_combn_koki.c
cat ./ft_print_combn_koki.c | sed -e $"s:^char :char\t:" -e $"s:^void :void\t:" -e $"s:^int :int\t:"> ./ft_print_combn_koki.c
