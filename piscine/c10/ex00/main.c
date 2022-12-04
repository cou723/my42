#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUF_MAX 1048576

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

int main(int argc, char *argv[])
{
	char buf[BUF_MAX];
	int	 fd;

	if (argc < 2)
	{
		putstr_r("File name missing.");
		return (0);
	}
	if (argc > 2)
	{
		putstr_r("Too many arguments.");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		putstr_r("Cannot read file.");
	else
	{
		buf[read(fd, buf, BUF_MAX - 1)] = '\0';
		putstr_r(buf);
	}
	close(fd);
}
