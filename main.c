#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// #include "libasm.a"

extern size_t   ft_strlen(const char* str);
extern char     *ft_strcpy(char* dest, const char* src);
extern int      ft_strcmp(const char* s1, const char* s2);

extern ssize_t  ft_write(int fd, const void *buf, size_t count);
void    set_errno(int value) {
    errno = value;
}
int main() {
    const char  *text = "Hello World!";

    printf("***** \e[1mFT_STRLEN \e[0m*****\n");

    size_t  len = ft_strlen(text);

    printf("\e[92mft_strlen: \e[0m%zu\n", len);
    printf("\e[91mstrlen: \e[0m%zu\n\n", strlen(text));

// **********************************************************************************************

    printf("***** \e[1mFT_STRCPY\e[0m*****\n");

    char    *newStr = malloc(sizeof(char) * ft_strlen(text)); 
    char    *cpy = ft_strcpy(newStr, text);

    printf("\e[92mft_strcpy: \e[0m'%s' copied to '%s'\n", text, cpy);
    printf("\e[91mstrcpy: \e[0m'%s' copied to '%s'\n\n", text, strcpy(newStr, text));

// **********************************************************************************************

    printf("***** \e[1mFT_STRCMP\e[0m*****\n");

    const char  *cmp = "Hello";

    printf("\e[92mft_strcmp: \e[0mCompare '%s' with '%s = %d\n", cmp, text, ft_strcmp(cmp, text));
    printf("\e[91mstrcmp: \e[0mCompare '%s' with '%s = %d\n", cmp, text, strcmp(cmp, text));
    printf("\e[92mft_strcmp: \e[0mCompare '%s' with '%s = %d\n", text, text, ft_strcmp(text, text));
    printf("\e[91mstrcmp: \e[0mCompare '%s' with '%s = %d\n\n", text, text, strcmp(text, text));

// **********************************************************************************************

    printf("***** \e[1mFT_WRITE\e[0m*****\n");

    write(0, text, strlen(text));
    write(0, "\n", 1);
    ft_write(0, text, strlen(text));
    write(0, "\n", 1);
    return 0;
}