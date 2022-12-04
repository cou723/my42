#!/bin/bash
cat ./ft_putnbr_base_debug.c | grep -v "printf" | grep -v "stdio.h" > ./ft_putnbr_base.c
cat ./ft_putnbr_base.c | sed -e $"s:^char  :char\t:" -e $"s:^void  :void\t:" -e $"s:^int\t  :int\t\t:"> ./ft_putnbr_base.c
cat ./ft_putnbr_base.c | sed -e $"s:^int\t  :int\t\t:"> ./ft_putnbr_base.c
cat ./ft_putnbr_base.c | sed -e $"s:^char :char\t:" -e $"s:^void :void\t:" -e $"s:^int :int\t:"> ./ft_putnbr_base.c
