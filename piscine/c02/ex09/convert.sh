#!/bin/bash
cat ./ft_strcapitalize_debug.c | grep -v "printf" | grep -v "stdio.h" > ./ft_strcapitalize.c
cat ./ft_strcapitalize.c | sed -e $"s:^char  :char\t:" -e $"s:^void  :void\t:" -e $"s:^int\t  :int\t\t:"> ./ft_strcapitalize.c
cat ./ft_strcapitalize.c | sed -e $"s:^int\t  :int\t\t:"> ./ft_strcapitalize.c
cat ./ft_strcapitalize.c | sed -e $"s:^char :char\t:" -e $"s:^void :void\t:" -e $"s:^int :int\t:"> ./ft_strcapitalize.c
