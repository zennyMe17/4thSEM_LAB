#include<stdio.h>
#include<stdlib.h>

#define N 5
int B[N];

void merge(int A[], int lb, int mid, int ub)
{
    int i, j, k;
    i = lb;
    j = mid + 1;
    k = lb;

    while (i <= mid && j <= ub)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            B[k] = A[i];
            k++;
            i++;
        }
    }
    for (i = lb; i <= ub; i++) {
        A[i] = B[i];
    }
}

void mergesort(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergesort(A, lb, mid);
        mergesort(A, mid + 1, ub);
        merge(A, lb, mid, ub);
    }
}

int main()
{
    int A[] = {55, 14, 3, 22, 15};
    mergesort(A, 0, 4);
    printf("Sorted Array:");
    for (int i = 0; i < N; i++)
    {
        printf("\t%d", A[i]);
    }
    return 0;
}
