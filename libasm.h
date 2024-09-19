#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

size_t   ft_strlen(const char* str);
char     *ft_strcpy(char* dest, const char* src);
int      ft_strcmp(const char* s1, const char* s2);
ssize_t  ft_write(int fd, const void *buf, size_t count);
char     *ft_strdup(const char *s);
ssize_t  ft_read(int fd, void *buf, size_t count);

#endif