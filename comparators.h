#ifndef COMPARATORS_H_INCLUDED
#define COMPARATORS_H_INCLUDED

bool CompareUp(int*, int*);
bool CompareDown(int*, int*);

bool CompareUp(int* a, int* b)
{
    return (*a < *b);
}

bool CompareDown(int* a, int* b)
{
    return (*a > *b);
}

#endif // COMPARATORS_H_INCLUDED
