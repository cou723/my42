1. ファイルからテキストを読み取る
2. 改行が含まれていた場合読み取りを中断する
3. 読み取ったテキストをstatic変数にあるものと合成しbufをつくる
4. static変数にあるものをfreeする
5. bufの/nまでを返す用の変数に複製する
6. bufの前を複製する
7. bufを/nの後を複製する
8. bufをfreeする
9.  static変数に6.で複製したモノを代入する
10. 5.をで複製したものをreturnする
11. ファイルからテキストを読み取る

static変数に保持するのは\n以降の文字列

## defence
leftover:残り
BUFFER_SIZEはint_max入れるとおかしくなるのでint_maxを入れる際には(size_t)を入れる必要がある

## 使用について
- 基本的にはmallocされた文字列を返す
- ファイルの列をすべて出力した場合はNULLを返す
  - 最後のNULLを返すとき以外はメモリがstaticに確保されている。
- ただしmallocエラーが出た場合のみ、全てをfreeしNULLを返す

## メモリ開放について
get_next_line.c:36 :失敗した場合はstrdup内のmallocによってerrnoが設定される、mallocから以下のif分までに使用されている関数strlen,strlcpyはerrnoを書き換えない。

get_next_line.c:44 :失敗した場合はlenに-1が入り、55行目で判定する
get_next_line.c:51 :失敗した場合はlenに-1が入り45行目でwhileを抜け、以下同上
get_next_line.c:103:その後即NULLチェック
get_next_line.c:124:その後即NULLチェック

```c
#include "get_next_line.h"

static char	*read_file(int fd);
static char	*get_after_ln(char *str);
static char	*get_before_ln(char *alloc_text);
static char	*buf_combine(char *s1, char const *s2);

char	*get_next_line(int fd)
{
	if (0 <= fd && fd <= OPEN_MAX && BUFFER_SIZE > 0)
		return (read_file(fd));
	return (NULL);
}

static char	*read_file(int fd)
{
	ssize_t		len;
	static char	*after_ln[OPEN_MAX + 1UL];
	char		read_buf[BUFFER_SIZE + 1UL];
	char		*fline;

	len = 0;
	errno = 0;
	fline = ft_strdup(after_ln[fd]); 
	if (errno == ENOMEM)
	{
		free(after_ln[fd]);
		return (NULL);
	}
	if (find_nl_code(after_ln[fd]) == NULL)
	{
		len = read(fd, read_buf, BUFFER_SIZE);
		while (len > 0)
		{
			read_buf[len] = '\0';
			fline = buf_combine(fline, read_buf);
			if (find_nl_code(fline) || fline == NULL)
				break ;
			len = read(fd, read_buf, BUFFER_SIZE);
		}
	}
	free(after_ln[fd]);
	if (len == -1)
	{
		free(fline);
		return (NULL);
	}
	after_ln[fd] = get_after_ln(fline);
	return (get_before_ln(fline));
}

// "text" must be allocated by malloc
// "text" IS FREED in this function.
static char	*get_before_ln(char *str)
{
	char	*newline_code_pos;
	size_t	before_len_ln;
	char	*before_ln;

	if (str == NULL || ft_strlen(str) == 0)
		return (NULL);
	newline_code_pos = find_nl_code(str);
	if (newline_code_pos == NULL)
		return (str);
	before_len_ln = ft_strlen(str) - ft_strlen(newline_code_pos) + 1 + 1;
	if (before_len_ln == 0)
		return (NULL);
	before_ln = malloc(sizeof(char) * before_len_ln);
	if (before_ln == NULL)
		return (NULL);
	ft_strlcpy(before_ln, str, before_len_ln);
	free(str);
	return (before_ln);
}

// "text" must contain a null character.
// if "text" doesnt contains it, return NULL.
// this functions DO NOT free "text".
static char	*get_after_ln(char *str)
{
	size_t	after_ln_len;
	char	*after_ln;

	if (str == NULL || find_nl_code(str) == NULL)
		return (NULL);
	after_ln_len = ft_strlen(find_nl_code(str) + 1);
	if (after_ln_len == 0)
		return (NULL);
	after_ln = malloc(sizeof(char) * after_ln_len);
	if (after_ln == NULL)
		return (NULL);
	ft_strlcpy(after_ln, find_nl_code(str)+1, after_ln_len);
	//printf("start:<%s>, num:<%ld>\n\n\n", find_nl_code(str)+1,
	//		after_ln_len);
	return (after_ln);
}

// This strjoin allows s1 to be null and free s1.
static char	*buf_combine(char *s1, char const *s2)
{
	char	*joined_str;
	size_t	malloc_len;
	size_t	joined_str_len;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	malloc_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_str = malloc(sizeof(char) * malloc_len);
	if (joined_str == NULL)
		return (NULL);
	ft_strlcpy(joined_str, s1, malloc_len);
	joined_str_len = 0;
	while (joined_str_len < malloc_len && joined_str[joined_str_len] != '\0')
		joined_str_len++;
	ft_strlcpy(joined_str + joined_str_len, s2, malloc_len - joined_str_len);
	free(s1);
	return (joined_str);
}
```
