#include "libasm.h"

int main() {
    errno = 0;
    const char  *text = "Hello World!\n";

    printf("***** \e[1mFT_STRLEN \e[0m*****\n");

    printf("\e[92mft_strlen: \e[0m%zu\n",  ft_strlen(text));
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

    printf("***** \e[1mFT_STRDUP\e[0m*****\n");

    char    *otherText = ft_strdup(text);
    printf("\e[92mft_dup\e[0m : %s\n", ft_strdup("Hello world!"));
    // free (otherText);

    otherText = strdup(text);
    printf("\e[91mdup\e[0m : %s = %s\n", text, otherText);
    free (otherText);

// **********************************************************************************************

    printf("***** \e[1mFT_WRITE\e[0m*****\n");

    write(0, "\e[92mwrite: \e[0m", strlen("\e[92mwrite: \e[0m"));
    write(0, text, strlen(text));
    printf("\e[1mERRNO \e[0m: %s\n\n", strerror(errno));
    errno = 0;
    write(0, "\e[91mft_write: \e[0m", strlen("\e[91mft_write: \e[0m"));
    ft_write(0, text, ft_strlen(text));
    printf("\e[1mERRNO \e[0m: %s\n\n", strerror(errno));
    errno = 0;
    ft_write(-1, text, ft_strlen(text));
    printf("\e[1mERRNO \e[0m: %s\n\n", strerror(errno));
    errno = 0;

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
    printf("\e[1mERRNO \e[0m: %s\n\n", strerror(errno));
    errno = 0;
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
    printf("\e[1mERRNO \e[0m: %s\n\n", strerror(errno));
    errno = 0;
    close(fd2);

    return 0;
}
