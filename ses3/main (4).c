#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "projet.h"

#define BUFFER_SIZE 200





int main(int argc, char const *argv[])
{
 int fd;
 
 if ( ( fd = open("file.txt",  O_RDONLY) ) == -1)
 {
  printf("file opening failed\n");
  exit(0);
 }else{
  printf("file opening successful\n");
  printf("file descriptor: %d\n", fd);
 }
 int i =1;
 char  *line ="" ;
  while (line != NULL)
	{
		line = read_lines(fd);
		if (line != NULL)
			printf("line[%d] : %s\n",i, line);
		i++;
		free(line);
	}
}

char * read_lines(int fd)
{
    char* line = get_next_line(fd);
    return line;
}




char* my_realloc(char* ptr, size_t size)
{
    char* temp;
    int i;

    temp = ptr;
    ptr = malloc(size);
    i = 0;
    while(temp[i])
    {
        ptr[i] = temp[i];
        i++;
    }
    free(temp);
    return (ptr);
}

char get_char(const int fd)
{
    static char buff[BUFFER_SIZE];
    static char* ptr_buff;
    static int len = 0;
    char c;

    if(len == 0)
    {
        len = read(fd, buff, BUFFER_SIZE);
        ptr_buff = (char*)&buff;
        if(len == 0)
            return (0);
    }
    c = *ptr_buff;
    ptr_buff++;
    len--;
    return c;
}

char *get_next_line(const int fd)
{
    char c;
    char* str;
    int len;

    len = 0;
    str = malloc(BUFFER_SIZE + 1);
    if (str == NULL)
        return (0);
    c = get_char(fd);
    while(c != '\n' && c != '\0')
    {
        str[len] = c;
        c = get_char(fd);
        len++;
        if(len % (BUFFER_SIZE+1) == 0)
            str = my_realloc(str, len + BUFFER_SIZE + 1);
    }
    str[len] = 0;
    if(c == 0 && str[0] == 0)
        return (0);
    return (str);
}