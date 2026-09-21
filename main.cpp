#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "MyString.h"
#include "Sorters.h"
#include "comparators.h"
//const char* s0 = "Hello";

const int INDEX_SIZE = 10000;
const int LINE_SIZE = 500;

size_t ReadFromFile(const char* name, const char* index[]);
void PrintFile(const char* index[], size_t nlines);
void clear_data(const char* index[], size_t nlines);

int main(void)
{

    const char* index[INDEX_SIZE];
    const char* copy_index[INDEX_SIZE];
    size_t nlines = ReadFromFile("Eugene_Onegin.txt", index);

    memcpy(copy_index, index, nlines * sizeof(char*));

    qsort(index, nlines, sizeof(char*), CompareStrsStart);
    PrintFile(index, nlines);

    QuickSort(index, nlines, sizeof(char*), CompareStrsEnd);
    PrintFile(index, nlines);

    PrintFile(copy_index, nlines);

    clear_data(index, nlines);

    /*int data[] = {1, 2, 3, 4, 5, 6};
    BubbleSort(data, 6, 4, CompareDown);
    PrintArr(data, 6);*/

    return 0;
}

size_t ReadFromFile(const char* name, const char* index[])
{
    FILE* input_file = fopen(name, "r");

    size_t nlines = 0;
    char buffer[INDEX_SIZE] = "";

    while (fgets(buffer, LINE_SIZE, input_file) != NULL)
    {
        if (Strcmp(buffer, "\n") != 0)
        {
            if ((strchr(buffer, '\n') == NULL) && (buffer[0] != '\0')) Strcat(buffer, "\n");
            index[nlines++] = strdup(buffer);
        }
    }
    fclose(input_file);

    return nlines;
}

void PrintFile(const char* index[], size_t nlines)
{
    FILE* output_file = fopen("output.txt", "a");
    for (size_t i = 0;i < nlines;++i) fprintf(output_file, "%s", index[i]);

    fprintf(output_file, "\n************************************************************************************************\n");

    fclose(output_file);
}

void clear_data(const char* index[], size_t nlines)
{
    for (size_t i = 0; i < nlines - 1;++i)
    {
        free((void*)(index[i]));
        index[i] = NULL;
    }
}
