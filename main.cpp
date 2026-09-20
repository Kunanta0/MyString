#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "MyString.h"
#include "Sorters.h"
#include "comparators.h"
//const char* s0 = "Hello";

size_t ReadFromFile(const char* name, const char* index[]);
void PrintFile(const char* index[], size_t nlines);

int main(void)
{
    const char* index[10000];
    const char* copy_index[10000];
    size_t nlines = ReadFromFile("Eugene Onegin (2).txt", index);
    ReadFromFile("Eugene Onegin (2).txt", copy_index);
    //BubbleSort(index, nlines, sizeof(char*), CompareStrs);
    BubbleSort(index, nlines, sizeof(char*), CompareStrs1);
    PrintFile(index, nlines);
    qsort(index, nlines, sizeof(char*), CompareStrs2);
    PrintFile(index, nlines);
    PrintFile(copy_index, nlines);

    //clear_data(index, nlines);
    return 0;
}

size_t ReadFromFile(const char* name, const char* index[])
{
    FILE* file = fopen(name, "r");

    size_t nlines = 0;
    char buffer[10000] = "";

    while (fgets(buffer, 200, file) != NULL)
    {
        if (Strcmp(buffer, "\n") != 0)
        {
            if ((strchr(buffer, '\n') == NULL) && (buffer[0] != '\0')) Strcat(buffer, "\n");
            index[nlines++] = strdup(buffer);
        }
    }
    fclose(file);

    return nlines;
}

void PrintFile(const char* index[], size_t nlines)
{
    FILE* fo = fopen("OutputS.txt", "a");
    for (int i = 0;i < nlines;++i) fprintf(fo, "%s", index[i]);

    fprintf(fo, "\n************************************************************************************************\n");

    fclose(fo);
}
