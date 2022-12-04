#!/bin/bash
cat ./ft_split.debug.c | grep -v "printf" | grep -v "stdio.h" | grep -v $'\tputs(' | grep -v "//puts(" | grep -v "//printf"> ./ft_split.c
cat ./ft_split.c | sed -e $"s:^char  :char\t:" -e $"s:^void  :void\t:" -e $"s:^int\t  :int\t\t:"> ./ft_split.c
cat ./ft_split.c | sed -e $"s:^int\t  :int\t\t:"> ./ft_split.c
cat ./ft_split.c | sed -e $"s:^char :char\t:" -e $"s:^void :void\t:" -e $"s:^int :int\t:"> ./ft_split.c
