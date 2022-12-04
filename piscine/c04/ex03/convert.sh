#!/bin/bash
cat ./ft_atoi_debug.c | grep -v "printf" | grep -v "stdio.h" > ./ft_atoi.c
cat ./ft_atoi.c | sed -e $"s:^char  :char\t:" -e $"s:^void  :void\t:" -e $"s:^int\t  :int\t\t:"> ./ft_atoi.c
cat ./ft_atoi.c | sed -e $"s:^int\t  :int\t\t:"> ./ft_atoi.c
cat ./ft_atoi.c | sed -e $"s:^char :char\t:" -e $"s:^void :void\t:" -e $"s:^int :int\t:"> ./ft_atoi.c
