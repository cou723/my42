#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUF_MAX 1048576

char *ft_strcat(char *dest, char *src);

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

int main(int argc, char *argv[])
{
	char buf[BUF_MAX];
	int	 fd;
	int	 index;

	index = 1;
	if (argc < 2)
	{
		putstr_r("File name missing.");
		return (0);
	}
	while (index < argc)
	{
		fd = open(argv[index], O_RDONLY);
		if (fd == -1)
		{
			put_error(errno,argv[0],argv[index]);
		}
		else
		{
			buf[read(fd, buf, BUF_MAX - 1)] = '\0';
			putstr_r(buf);
			close(fd);
		}
		index++;
	}
}
