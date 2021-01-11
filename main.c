#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

#define LEN_TEST(val) "O: %zu\t <=> \tM: %zu\n", strlen(val), ft_strlen(val)
#define CPY_TEST(val1, val2) "O: |%s|\nM: |%s|\n\n", strcpy(val1, val2), ft_strcpy(val1, val2)
#define CMP_TEST(val1, val2) "O: %d <=> %d\n", strcmp(val1, val2), ft_strcmp(val1, val2)
#define DUP_TEST(val) "M: |%s|\nO: |%s|\n\n", ft_strdup(val), strdup(val)

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
	//strlen("hakam");
	// printf(STR_TEST(""));
	// printf(STR_TEST("hakam"));
	// printf(STR_TEST("hakam                   \n     "));
	// printf(STR_TEST("hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam"));
	
	/* ************************** */
	// char *str = "hakam";
	// char *str1 = new_str_empty(10);
	// printf(CPY_TEST(str1, str));
	// str1 = new_str_empty(600);
	// printf(CPY_TEST(str1, "hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam"));
	// printf(CPY_TEST(str1, ""));
	
	/* ************************** */
	// char str[] = "hakam";
	// printf(CMP_TEST("abc", "abc"));
	// printf(CMP_TEST("abc", "ab"));
	// printf(CMP_TEST("ab", "abc"));
	// printf(CMP_TEST(str, "abc"));
	// printf(CMP_TEST("abc", str));
	// printf(CMP_TEST("abc", NULL));

	/* ************************** */
	char str[] = "hakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakamhakam hakam";
	char *str2 = new_str("hakam hakam");
	char str3[] = {'h', 'a', 'k', '\0'};
	printf(DUP_TEST(str));
	printf(DUP_TEST(str2));
	printf(DUP_TEST(str3));
	printf(DUP_TEST(""));
	printf(DUP_TEST("hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam hakam"));
	
	return (0);
}