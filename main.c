#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

#define LEN_TEST(val) "M: %zu\t <=> \tO: %zu\n", ft_strlen(val), strlen(val)
#define CPY_TEST(val1, val2) "M: |%s|\nO: |%s|\n\n", ft_strcpy(val1, val2), strcpy(val1, val2)
#define CMP_TEST(val1, val2) "M: %d\t <=> \tO: %d\n", ft_strcmp(val1, val2), strcmp(val1, val2)
#define DUP_TEST(val) "M: |%s|\nO: |%s|\n\n", ft_strdup(val), strdup(val)
#define WRT_TEST(fd, len, buff, r1, r2) r1 = ft_write(fd, buff, len); write(1, "\n", 1); r2 = write(fd, buff, len);
#define RD_TEST(fd, len, buff, r1, r2) fd = open("./read_test.txt", O_RDONLY); r1 = ft_read(fd, buff, len); close(fd); write(1, buff, len); write(1, "\n", 1); fd = open("./read_test.txt", O_RDONLY); r2 = read(fd, buff, len); close(fd); write(1, buff, len);
#define WRT_ERR_TEST(X) printf("%s => ERRNO= |%d| MSG= |%s|\n", X, errno, strerror(errno));
#define RD_ERR_TEST(X) printf("%s => ERRNO= |%d| MSG= |%s|\n", X, errno, strerror(errno));

char *new_str(const char *str) {
	char *out = (char *)malloc(strlen(str) * sizeof(char));
	out = strcpy(out, str);
	return (out);
}

char *new_str_empty(size_t len) {
	char *out = (char *)malloc(len * sizeof(char));
	return (out);
}

int		main(void)
{
	char *str = "hakam";
	char *str2 = new_str("hakam hakam");
	char str3[] = {'h', 'a', 'k', '\0'};
	char str4[] = "start hakam hakamhakam hakamhakam hakamhakam hakamhakam \
	hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam \
	hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam \
	hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam \
	hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam \
	hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam \
	hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam \
	hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam \
	hakamhakam end";
	char *str5 = new_str("hey I'am an allocated string!");
	char *str6 = "hey I'am a stack string!";


	printf("\033[0;32m\n=============== STRLEN TESTS ===============\n\033[0m");
	printf(LEN_TEST(""));
	printf(LEN_TEST("hakam"));
	printf(LEN_TEST("hakam                   \n     "));
	printf(LEN_TEST(str4));
	printf(LEN_TEST(str6));
	printf(LEN_TEST("start hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam end"));


	printf("\033[0;32m\n=============== STRCMP TESTS ===============\n\033[0m");
	printf(CMP_TEST("abc", "abc"));
	printf(CMP_TEST("abc", "ab"));
	printf(CMP_TEST("ab", "abc"));
	printf(CMP_TEST(str, "abc"));
	printf(CMP_TEST("abc", str));
	printf(CMP_TEST("", ""));
	printf(CMP_TEST(str, str));


	printf("\033[0;32m\n=============== STRCPY TESTS ===============\n\033[0m");
	char *str_empty = new_str_empty(10);
	printf(CPY_TEST(str_empty, str));
	free(str_empty);
	str_empty = new_str_empty(600);
	printf(CPY_TEST(str_empty, "start hakam hakam hakam hakam hakam hakam hakam\
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam end"));
	printf(CPY_TEST(str_empty, ""));
	free(str_empty);


	printf("\033[0;32m\n=============== STRDUP TESTS ===============\n\033[0m");
	printf(DUP_TEST(str));
	printf(DUP_TEST(str2));
	printf(DUP_TEST(str3));
	printf(DUP_TEST(""));
	printf(DUP_TEST("start hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam end"));


	printf("\033[0;32m\n=============== WRITE TESTS ===============\033[0m\n");
	ssize_t w1, w2;
	WRT_TEST(1, 5, "hakam", w1, w2)
	printf("\nM: %zu | O: %zu\n", w1, w2);
	WRT_TEST(1, 2, "hakam", w1, w2)
	printf("\nM: %zu | O: %zu\n", w1, w2);
	WRT_TEST(1, 2, "", w1, w2)
	printf("\nM: %zu | O: %zu\n", w1, w2);
	WRT_TEST(1, 0, "hakam", w1, w2)
	printf("\nM: %zu | O: %zu\n", w1, w2);
	WRT_TEST(2, 18, "error message test", w1, w2)
	printf("\nM: %zu | O: %zu\n", w1, w2);
	WRT_TEST(1, ft_strlen(str), str, w1, w2)
	printf("\nM: %zu | O: %zu\n", w1, w2);
	WRT_TEST(1, ft_strlen(str2), str2, w1, w2)
	printf("\nM: %zu | O: %zu\n", w1, w2);
	WRT_TEST(1, 200, "start hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam \
	end", w1, w2)
	printf("\nM: %zu | O: %zu\n", w1, w2);
	WRT_TEST(1, 50, "start hakam hakam hakam hakam hakam hakam hakam hakam \
	hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam end", w1, w2)
	printf("\nM: %zu | O: %zu\n", w1, w2);


	printf("\033[0;32m\n=============== WRITE ERROR TESTS ===============\n\033[0m");
	ft_write(-1, str, ft_strlen(str));
	WRT_ERR_TEST("M")
	ft_write(1, NULL, 1);
	WRT_ERR_TEST("M")
	ft_write(1, str2, -1);
	WRT_ERR_TEST("M")

	write(-1, str, ft_strlen(str));
	WRT_ERR_TEST("O")
	write(1, NULL, 1);
	WRT_ERR_TEST("O")
	write(1, str2, -1);
	WRT_ERR_TEST("O")

	printf("\033[0;32m\n=============== READ TESTS ===============\n\033[0m");
	int fd;
	str_empty = new_str_empty(100);
	ssize_t r1, r2;
	RD_TEST(fd, 1, str_empty, r1, r2)
	printf("\nM: %zu | O: %zu\n", r1, r2);
	RD_TEST(fd, 10, str_empty, r1, r2)
	printf("\nM: %zu | O: %zu\n", r1, r2);
	RD_TEST(fd, 5, str_empty, r1, r2)
	printf("\nM: %zu | O: %zu\n", r1, r2);
	RD_TEST(fd, 100, str_empty, r1, r2)
	printf("\nM: %zu | O: %zu\n", r1, r2);

	printf("\033[0;32m\n=============== READ ERROR TESTS ===============\n\033[0m");
	fd = open("./read_test.txt", O_RDONLY);
	ft_read(-1, str_empty, 100);
	RD_ERR_TEST("M")
	ft_read(fd, NULL, 1);
	RD_ERR_TEST("M")
	ft_read(fd, str_empty, -1);
	RD_ERR_TEST("M")

	read(-1, str_empty, 100);
	RD_ERR_TEST("O")
	read(fd, NULL, 1);
	RD_ERR_TEST("O")
	read(fd, str_empty, -1);
	RD_ERR_TEST("O")

	close(fd);
	free(str_empty);

	free(str2);
	free(str5);
	return (0);
}