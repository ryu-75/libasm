#include "libasm.h"

#define FT(func) ft_##func

int main() {
    errno = 0;

    printf("***** \e[1mFT_STRLEN \e[0m*****\n");

    printf("\e[92mft_strlen: \e[0m%zu\n",  FT(strlen)(""));
    printf("\e[92mft_strlen: \e[0m%zu\n\n",  FT(strlen)("Hello World!"));

    printf("\e[91mstrlen: \e[0m%zu\n", strlen(""));
    printf("\e[91mstrlen: \e[0m%zu\n\n", strlen("Hello World!"));

// **********************************************************************************************

    printf("***** \e[1mFT_STRCPY\e[0m*****\n");
    char    dest[60] = {0};
    printf("\e[92mft_strcpy: \e[0m'%s'\n", FT(strcpy)(dest, ""));
    printf("\e[92mft_strcpy: \e[0m'%s'\n", FT(strcpy)(dest, "Hello World!"));
    printf("\e[92mft_strcpy: \e[0m'%s'\n\n", FT(strcpy)(dest, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));

    printf("\e[91mstrcpy: \e[0m'%s'\n", strcpy(dest, ""));
    printf("\e[91mstrcpy: \e[0m'%s'\n", strcpy(dest, "Hello World!"));
    printf("\e[91mstrcpy: \e[0m'%s'\n\n", strcpy(dest, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));

// **********************************************************************************************

    printf("***** \e[1mFT_STRCMP\e[0m*****\n");

    printf("\e[92mft_strcmp: \e[0m%d\n", FT(strcmp)("aaaaa", "aaaaa"));
    printf("\e[92mft_strcmp: \e[0m%d\n", FT(strcmp)("aaaab", "aaaaa"));
    printf("\e[92mft_strcmp: \e[0m%d\n", FT(strcmp)("aaaaa", "aaaab"));
    printf("\e[92mft_strcmp: \e[0m%d\n\n", FT(strcmp)("", ""));

    printf("\e[91mstrcmp: \e[0m%d\n", strcmp("aaaaa", "aaaaa"));
    printf("\e[91mstrcmp: \e[0m%d\n", strcmp("aaaab", "aaaaa"));
    printf("\e[91mstrcmp: \e[0m%d\n", strcmp("aaaaa", "aaaab"));
    printf("\e[91mstrcmp: \e[0m%d\n\n", strcmp("", ""));

// **********************************************************************************************

    printf("***** \e[1mFT_STRDUP\e[0m*****\n");

    printf("\e[92mft_strdup\e[0m : %s\n", FT(strdup)(""));
    printf("\e[92mft_strdup\e[0m : %s\n", FT(strdup)("Hello world!"));
    printf("\e[92mft_strdup\e[0m : %s\n\n", FT(strdup)("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));

    printf("\e[91mstrdup\e[0m : %s\n", strdup(""));
    printf("\e[91mstrdup\e[0m : %s\n", strdup("Hello world!"));
    printf("\e[91mstrdup\e[0m : %s\n\n", strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));

// **********************************************************************************************

    printf("***** \e[1mFT_WRITE\e[0m*****\n");

    write(0, "\e[91mwrite: \e[0m", strlen("\e[92mwrite: \e[0m"));
    write(0, "Hello World!\n", strlen("Hello World!\n"));
    printf("\e[1mERRNO \e[0m: %s\n", strerror(errno));
    errno = 0;

    write(0, "\e[91mwrite: \e[0m", strlen("\e[92mwrite: \e[0m"));
    write(0, "", strlen(""));
    printf("\e[1mERRNO \e[0m: %s\n", strerror(errno));
    errno = 0;

    write(0, "\e[91mwrite: \e[0m", strlen("\e[92mwrite: \e[0m"));
    write(-1, "Hello World!", strlen("Hello World!"));
    printf("\e[1mERRNO \e[0m: %s\n\n", strerror(errno));
    errno = 0;

// **********************************************************************************************

    write(0, "\e[92mft_write: \e[0m", strlen("\e[91mft_write: \e[0m"));
    FT(write)(0, "Hello World!\n", FT(strlen)("Hello World!\n"));
    printf("\e[1mERRNO \e[0m: %s\n", strerror(errno));
    errno = 0;

    write(0, "\e[92mft_write: \e[0m", strlen("\e[91mft_write: \e[0m"));
    FT(write)(0, "", ft_strlen(""));
    printf("\e[1mERRNO \e[0m: %s\n", strerror(errno));
    errno = 0;

    write(0, "\e[92mft_write: \e[0m", strlen("\e[91mft_write: \e[0m"));
    FT(write)(-1, "Hello World!", FT(strlen)("Hello World!"));
    printf("\e[1mERRNO \e[0m: %s\n\n", strerror(errno));
    errno = 0;

// **********************************************************************************************

    printf("***** \e[1mFT_READ\e[0m*****\n");

    char    buf1[50] = { 0 };
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

// ******************************************************************************************

    char    buf2[50] = { 0 };
    int fd2 = open("source/ft_strlen.s", O_RDONLY);

    if (fd2 == -1) {
        perror("open");
        return 1;
    }
    ssize_t  bytes2 = FT(read)(fd2, buf2, sizeof(buf2) - 1);

    buf2[bytes2] = '\0';

    printf("\e[92mft_read: \e[0m'%s'\n", buf2);
    printf("\e[1mERRNO \e[0m: %s\n\n", strerror(errno));
    errno = 0;
    close(fd2);

    char    buf3[50] = {0};
    ssize_t  bytes3 = FT(read)(-1, buf3, sizeof(buf3) - 1);
    buf3[bytes3] = '\0';

    printf("\e[92mft_read: \e[0m'%s'\n", buf3);
    printf("\e[1mERRNO \e[0m: %s\n\n", strerror(errno));
    errno = 0;

    return 0;
}
