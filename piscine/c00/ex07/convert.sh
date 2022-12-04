#!/bin/bash
cat ./ft_putnbr_debug.c | grep -v "printf" | grep -v "stdio.h" > ./ft_putnbr.c
cat ./ft_putnbr.c | sed -e $"s:^char  :char\t:" -e $"s:^void  :void\t:" -e $"s:^int\t  :int\t\t:"> ./ft_putnbr.c
cat ./ft_putnbr.c | sed -e $"s:^int\t  :int\t\t:"> ./ft_putnbr.c
cat ./ft_putnbr.c | sed -e $"s:^char :char\t:" -e $"s:^void :void\t:" -e $"s:^int :int\t:"> ./ft_putnbr.c
