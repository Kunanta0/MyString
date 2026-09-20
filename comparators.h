#ifndef COMPARATORS_H_INCLUDED
#define COMPARATORS_H_INCLUDED

int CompareUp(const void*, const void*);
int CompareDown(const void*, const void*);
int CompareStrs1(const void*, const void*);
int CompareStrs2(const void*, const void*);

int CompareUp(const void* value_a, const void* value_b)
{
    const int a = *(const int*) value_a;
    const int b = *(const int*) value_b;

    return (a < b);
}

int CompareDown(const void* value_a, const void* value_b)
{
    const int a = *(const int*) value_a;
    const int b = *(const int*) value_b;

    return (a > b);
}

int CompareStrs2(const void* a, const void* b)
{
    /*const char* str1 = *(const char**) a;
    const char* str2 = *(const char**) b;

    size_t max_size = (Strlen(str1) > Strlen(str2)) ? Strlen(str1) : Strlen(str2);

    for (size_t i = 0, j = 0; i < max_size, j < max_size; ++i, ++j)
    {
        char ch1 = *(str1 + i);
        char ch2 = *(str2 + i);
        while (!(isalpha(ch1)))
        {
            ++i;
            ch1 = *(str1 + i);
        }
        while (!(isalpha(ch2)))
        {
            ++j;
            ch2 = *(str2 + j);
        }
        int s1 = ch1 = tolower(ch1);
        int s2 = ch2 = tolower(ch2);

        if (s1 != s2) return s1 - s2;
    }

    return 0;*/

    const char* s1 = *(const char**) a;
    const char* s2 = *(const char**) b;

    size_t i1 = strlen(s1) - 1;
    size_t i2 = strlen(s2) - 1;

    s1 += i1;
    s2 += i2;


    while (*s1 && *s2)
    {
        while(*s1 && !isalpha((unsigned char)*s1)) s1--;
        while(*s2 && !isalpha((unsigned char)*s2)) s2--;

        if(!*s1 || !*s2) break;

        int c1 = tolower((unsigned char)*s1);
        int c2 = tolower((unsigned char)*s2);

        if (c1 != c2) return c1 - c2;

        s1--;
        s2--;
    }

    while(*s1 && !isalpha((unsigned char)*s1)) s1--;
    while(*s2 && !isalpha((unsigned char)*s2)) s2--;

    return (unsigned char)* s1 - (unsigned char)* s2;
}

int CompareStrs1(const void* a, const void* b)
{
    const char* s1 = *(const char**) a;
    const char* s2 = *(const char**) b;

    while (*s1 && *s2)
    {
        while(*s1 && !isalpha((unsigned char)*s1)) s1++;
        while(*s2 && !isalpha((unsigned char)*s2)) s2++;

        if(!*s1 || !*s2) break;

        int c1 = tolower((unsigned char)*s1);
        int c2 = tolower((unsigned char)*s2);

        if (c1 != c2) return c1 - c2;

        s1++;
        s2++;
    }

    while(*s1 && !isalpha((unsigned char)*s1)) s1++;
    while(*s2 && !isalpha((unsigned char)*s2)) s2++;

    return (unsigned char)* s1 - (unsigned char)* s2;
}

#endif // COMPARATORS_H_INCLUDED
