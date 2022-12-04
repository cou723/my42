#!/bin/bash
cat ./ft_split.debug.c | grep -v "printf" | grep -v "stdio.h" | grep -v $'\tputs(' | grep -v "//puts(" | grep -v "//printf"\
| sed -e $"s:^char  :char\t:" -e $"s:^void  :void\t:" -e $"s:^int\t  :int\t\t:"\
| sed -e $"s:^int\t  :int\t\t:"| sed -e $"s:^char :char\t:" -e $"s:^void :void\t:" -e $"s:^int :int\t:" | grep -v "//"> ./ft_split.c
