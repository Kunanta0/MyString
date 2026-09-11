#ifndef SORTERS_H_INCLUDED
#define SORTERS_H_INCLUDED

void Swap(int*, int*);
void BubbleSort(int*, size_t, bool (*CompareFunc) (int*, int*));
void QuickSort(int*, size_t, bool (*CompareFunc) (int*, int*), size_t);

void Swap(int* a1, int* a2)
{
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void QuickSort(int* arr, size_t SIZE, bool (*CompareFunc) (int* a, int* b), size_t lo = 0)
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

void BubbleSort(int* arr, size_t SIZE, bool (*CompareFunc) (int* a, int* b))
{
    for (size_t n = SIZE - 1;n >= 0;--n)
    {
        bool IsChanged = false;
        for (size_t i = 0;i < n;++i)
        {
            if (CompareFunc(arr + i, arr + i + 1))
            {
                Swap(arr + i, arr + i + 1);
                IsChanged = true;
            }
        }
        if (!IsChanged) return;
    }
}

#endif // SORTERS_H_INCLUDED
