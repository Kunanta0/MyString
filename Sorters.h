#ifndef SORTERS_H_INCLUDED
#define SORTERS_H_INCLUDED

void Swap(void*, void*);
void BubbleSort(void*, size_t, size_t, int (*CompareFunc) (const void*, const void*));
void QuickSort(int*, size_t, bool (*CompareFunc) (const void*, const void*), size_t);

void Swap(void* value_1, void* value_2)
{
    int* a1 = (int*) value_1;
    int* a2 = (int*) value_2;

    int* temp = a1;
    a1 = a2;
    a2 = temp;
}

void QuickSort(int* arr, size_t SIZE, bool (*CompareFunc) (const void* a, const void* b), size_t lo = 0)
{
    size_t  hi = SIZE - 1;
    if (lo >= hi) return;

    int pivot = *(arr + hi);
    size_t i = lo;
    for (size_t j = lo; j < hi; ++j)
    {
        if (/* *(arr + j) < pivot*/ CompareFunc(arr + j, &pivot))
        {
            Swap(arr + i, arr + j);
            ++i;
        }
    }
    Swap(arr + i, arr + hi);
    if (i != 0) QuickSort(arr, i, CompareFunc, lo);
    QuickSort(arr, hi + 1, CompareFunc, i + 1);
}

void BubbleSort(void* data, size_t nnums, size_t SIZE, int (*CompareFunc) (const void* a, const void* b))
{
    char* arr = (char*) data;
    for (size_t n = nnums - 1;n >= 0;--n)
    {
        bool IsChanged = false;
        for (size_t i = 0;i < n;++i)
        {
            void* temp = malloc(SIZE);
            void* arr1 = arr + i * SIZE;
            void* arr2 = arr + (i + 1) * SIZE;
            if (CompareFunc(arr1, arr2) > 0)
            {
                memcpy(temp, arr1, SIZE);
                memcpy(arr1, arr2, SIZE);
                memcpy(arr2, temp, SIZE);
                IsChanged = true;
            }
            free(temp);
        }
        if (!IsChanged) return;
    }
}

#endif // SORTERS_H_INCLUDED
