#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//const char* s0 = "Hello";

int Puts(const char*);
size_t Strlen(const char*);
char* Strcpy(char* , const char* );
char* Strcat(char*, const char*);
int Strcmp(const char*, const char*);

int main(void)
{
    /*char* s1 = (char*)calloc(10, sizeof(char));
    for (int i = 0; i < 3; ++i)
    {
        s1[i] = 'A';
    }
    s1[3] = 'B';
    s1[4] = '\0';

    const char s2[] = {'H', 'E', 'L', 'L', 'O', '\0'};
    Strcat(s1, s2);
    printf("%s\n", s1);*/

    /*int Size = Strlen(s1);
    printf("Strlen(%s) = %d\n", s1, Size);*/

    //Puts("abcdef");

    /*int ans = Strcmp("apples", "apple");

    printf("Strcmp returns %d", ans);*/

    return 0;
}

size_t Strlen(const char* s)
{
    size_t answer = 0;
    while (*s++ != '\0') ++answer;
    return answer;
}

int Puts(const char* s)
{
    while(*s != '\0')
    {
        putchar(*s);
        ++s;
    }
    putchar('\n');
    return 0;
}

char* Strcpy(char* dest, const char* src)
{
    size_t Size = Strlen(src);
    for (int i = 0;i < Strlen(src);++i)
    {
        *(dest + i) = src[i];
    }
    *(dest + Size) = 0;

    return dest;
}

char* Strcat(char* dest, const char* src)
{
    char* current = dest + Strlen(dest);
    size_t Size = Strlen(src) + Strlen(dest);
    int i = Strlen(dest);
    for (int j = 0;j < Strlen(src);++j)
    {
        *(dest + i) = src[j];
        ++i;
    }
    *(dest + Size) = 0;

    return dest;
}

int Strcmp(const char* str1, const char* str2)
{
    size_t max_size = (Strlen(str1) > Strlen(str2)) ? Strlen(str1) : Strlen(str2);

    for (int i = 0; i < max_size; ++i)
    {
        int s1 = *(str1 + i);
        int s2 = *(str2 + i);

        if (s1 != s2) return s1 - s2;
    }

    return 0;
}
