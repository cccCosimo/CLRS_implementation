#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RANDOMLY_PERMUTE(int *, int);
int *RANDOM_SAMPLE(int, int);

int Search(int *, int);

int main(void)
{
    srand((unsigned)time(NULL));
    int m = 6;
    int n = 18;

    // RANDOM_PERMUTE test
    printf("----------------RANDOM_PERMUTE test-----------------\n\n");
    int A[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
    RANDOMLY_PERMUTE(A, n);
    printf("we only take the first %d elements of A, and that is : \n", m);
    for (int j = 0; j < m; j++)
    {
        printf("%d ", A[j]);
    }

    // RANDOM_SAMPLE test
    printf("\n\n");
    printf("----------------RANDOM_SAMPLE test-----------------\n\n");
    int *B;
    B = RANDOM_SAMPLE(m, n);
    printf("this method return array with exactly %d elements, and that is\n", m);
    for (int i = 0; i < m; i++)
    {
        printf("%d ", B[i]);
    }
    free(B);
    return 0;
}

//---------------------------------------------
int *RANDOM_SAMPLE(int m, int n)
{
    int *S = (int *)malloc(m * sizeof(int));
    int i;
    int index;
    int count = 0;
    for (int k = n - m; k < n; k++)
    {
        i = 1 + rand() % (k + 1);
        index = Search(S, i);
        if (index >= 0)
        {
            S[count] = k;
        }
        else
        {
            S[count] = i;
        }
        count++;
    }

    return S;
}

int Search(int *arr, int x)
{
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (x == arr[i])
        {
            index = i;
        }
    }

    return index;
}

void RANDOMLY_PERMUTE(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        int index = i + rand() % (n - i);
        if (index == i)
            continue;
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}