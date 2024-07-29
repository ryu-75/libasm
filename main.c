#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

// #include "libasm.a"

extern size_t   ft_strlen(const char* str);
extern char     *ft_strcpy(char* dest, const char* src);
extern int      ft_strcmp(const char* s1, const char* s2);

extern ssize_t  ft_write(int fd, const void *buf, size_t count);
extern char *ft_strdup(const char *s);
extern ssize_t  ft_read(int fd, void *buf, size_t count);
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

    char    *newStr = malloc(sizeof(char) * ft_strlen(text) + 1); 

    if (newStr == NULL) {
        perror("malloc");
        return 1;
    }
    char    *cpy = ft_strcpy(newStr, text);

    printf("\e[92mft_strcpy: \e[0m'%s' copied to '%s'\n", text, cpy);
    printf("\e[91mstrcpy: \e[0m'%s' copied to '%s'\n\n", text, strcpy(newStr, text));

    free(newStr);

// **********************************************************************************************

    printf("***** \e[1mFT_STRCMP\e[0m*****\n");

    const char  *cmp = "Hello";

    printf("\e[92mft_strcmp: \e[0mCompare '%s' with '%s = %d\n", cmp, text, ft_strcmp(cmp, text));
    printf("\e[91mstrcmp: \e[0mCompare '%s' with '%s = %d\n", cmp, text, strcmp(cmp, text));
    printf("\e[92mft_strcmp: \e[0mCompare '%s' with '%s = %d\n", text, text, ft_strcmp(text, text));
    printf("\e[91mstrcmp: \e[0mCompare '%s' with '%s = %d\n\n", text, text, strcmp(text, text));

// **********************************************************************************************

    printf("***** \e[1mFT_WRITE\e[0m*****\n");

    write(1, "\e[91mft_write: \e[0m", strlen("\e[91mft_write: \e[0m"));
    ft_write(1, text, strlen(text));
    write(1, "\n", 1);

    write(1, "\e[92mwrite: \e[0m", strlen("\e[92mwrite: \e[0m"));
    write(1, text, strlen(text));
    write(1, "\n", 1);

// **********************************************************************************************

    printf("***** \e[1mFT_READ\e[0m*****\n");
    
    char    buf1[1024];
    int fd1 = open("source/ft_strlen.s", O_RDONLY);

    if (fd1 == -1) {
        perror("open");
        return 1;
    }
    ssize_t  bytes1 = read(fd1, buf1, sizeof(buf1) - 1);

    buf1[bytes1] = '\0';

    printf("\e[91mread: \e[0m'%s'\n", buf1);
    close(fd1);

    char    buf2[1024];
    int fd2 = open("source/ft_strlen.s", O_RDONLY);

    if (fd2 == -1) {
        perror("open");
        return 1;
    }

    ssize_t  bytes2 = ft_read(fd2, buf2, sizeof(buf2) - 1);

    buf2[bytes2] = '\0';
    
    printf("\e[92mft_read: \e[0m'%s'\n", buf2);
    close(fd2);
    
// **********************************************************************************************

    printf("***** \e[1mFT_STRDUP\e[0m*****\n");

    char    *otherText = ft_strdup(text);
    printf("\e[92mft_dup\e[0m : %s = %s\n", text, otherText);
    free (otherText);
    
    otherText = strdup(text);
    printf("\e[91mdup\e[0m : %s = %s\n", text, otherText);
    free (otherText);

    return 0;
}