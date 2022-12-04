#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUF_MAX 1048576

char *ft_strcat(char *dest, char *src);
int	  ft_strcmp(char *s1, char *s2);
int	  ft_atoi(char *str);
int	  ft_strlen(char *str);

void putstr_r(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void put_error(int error_num, char *name, char *file)
{
	char err_msg[765];

	ft_strcat(err_msg, basename(name));
	ft_strcat(err_msg, ": ");
	ft_strcat(err_msg, basename(file));
	ft_strcat(err_msg, ": ");
	ft_strcat(err_msg, strerror(error_num));
	putstr_r(err_msg);
}

void put_n_chara(int count, char *str)
{
	char *output_str;

	if (count == -1)

		if (count > ft_strlen(str))
			putstr_r(str);
		else
			putstr_r(str[ft_strlen(str) - count]);
}

void get_line(char *str)
{
	int line;

	line = 1;
	str--;
	while (*str++ != '\0')
	{
		if (*str == '\n')
			line++;
	}
	return (line);
}

void tail_core(int op_str_ct, int file_ct, char *files[])
{
	char buf[BUF_MAX];
	int	 index;
	int	 fd;

	index = 0;
	while (index < file_ct)
	{

		fd = open(argv[index], O_RDONLY);
		if (fd == -1)
			put_error(errno, argv[0], argv[index]);
		else
		{
			buf[read(fd, buf, BUF_MAX - 1)] = '\0';
			if(op_str_ct ==-1)
				put_n_chara(op_str_ct, buf);
			else
				put_n_chara(op_str_ct, buf);
			close(fd);
		}
		index++;
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		putstr_r("File name missing.");
	else
	{
		if (ft_strcmp(argv[2], "-c"))
			tail_core(ft_atoi(argv[2]), argc - 3, argv[3]);
		else
			tail_core(-1, argc - 1, argv[1]);
	}
}
