#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "libasm.a"

extern size_t   ft_strlen(const char* str);
extern char     *ft_strcpy(char* dest, const char* src);
int main() {
    const char  *text = "Hello World!";

    printf("***** \e[1mFT_STRLEN \e[0m*****\n");
    size_t  len = ft_strlen(text);
    printf("\e[92mft_strlen: \e[0m%zu\n", len);
    printf("\e[92mstrlen: \e[0m%zu\n\n", strlen(text));

    printf("***** \e[1mFT_STRCPY\e[0m*****\n");
    char    *newStr = malloc(sizeof(char) * ft_strlen(text)); 
    char    *cpy = ft_strcpy(newStr, text);
    printf("\e[92mft_strcpy: \e[0m'%s' copied to '%s'\n", text, cpy);
    printf("\e[92mstrcpy: \e[0m'%s' copied to '%s'\n", text, strcpy(newStr, text));
    
    return 0;
}