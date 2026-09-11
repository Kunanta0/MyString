#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "MyString.h"
#include "Sorters.h"
#include "comparators.h"
//const char* s0 = "Hello";

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
    Strcpy(s1, s2);
    printf("%s\n", s1);*/

    /*int Size = Strlen(s1);
    printf("Strlen(%s) = %d\n", s1, Size);*/

    //Puts("abcdef");

    /*int ans = Strcmp("apples", "apple");

    printf("Strcmp returns %d", ans);*/

    int SIZE = 0;
    scanf("%d", &SIZE);

    int* data = (int *)calloc(SIZE, sizeof(int));

    for (int i = 0;i < SIZE;++i)
    {
        scanf("%d", data + i);
    }

    //BubbleSort(data, SIZE, CompareUp);
    QuickSort(data, 0, SIZE-1, CompareDown);

    PrintArr(data, SIZE);

    return 0;
}
