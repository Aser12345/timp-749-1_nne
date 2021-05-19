#include <stdio.h>
#include <stdlib.h>

void SD(int* a, int root, int bottom, int length, FILE* fp)
{
    int j, t;
    int maxChild;
    int done = 0;

    while ((root * 2 <= bottom) && (!done))
    {

        if (root * 2 == bottom)
        {
            maxChild = root * 2;
        }
        else
        {
            if (a[root * 2] > a[root * 2 + 1])
                maxChild = root * 2;
            else
                maxChild = root * 2 + 1;

        }
        if (a[root] < a[maxChild])
        {
            t = a[root];
            a[root] = a[maxChild];
            a[maxChild] = t;
            root = maxChild;

            for (j = 0; j < length; j++)
            {
                if (j != 0)
                    fprintf(fp, " ");
                fprintf(fp, "%d", a[j]);
            }
            fprintf(fp, "\n");

        }
        else
            done = 1;

    }
}

void heap(int* a, int length, FILE* fp)
{
    int t, j;
    for (int i = (length / 2); i >= 0; i--)
    {
        SD(a, i, length - 1, length, fp);

    }

    for (int i = length - 1; i >= 1; i--)
    {
        t = a[0];
        a[0] = a[i];
        a[i] = t;

        for (j = 0; j < length; j++)
        {
            if (j != 0)
                fprintf(fp, " ");
            fprintf(fp, "%d", a[j]);
        }
        fprintf(fp, "\n");

        SD(a, 0, i - 1, length, fp);
    }
}
void Quick_Sorting(int* arr, int first, int last, FILE* fp, int length)
{
    int temp, i;
    int left, right, middle;
    if (first < last)
    {
        left = first;
        right = last;
        middle = arr[(left + right) / 2];

        do
        {
            while (arr[left] < middle) { left++; }
            while (arr[right] > middle) { right--; }

            if (left <= right)
            {
                temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;


                for (i = 0; i < length; i++)
                {
                    if (i != 0)
                        fprintf(fp, " ");
                    fprintf(fp, "%d", arr[i]);
                }
                fprintf(fp, "\n");

            }
        } while (left <= right);

        quick(arr, first, right, fp, length);
        quick(arr, left, last, fp, length);
    }
}


int main()
{
    int length, i;
    scanf("%d", &length);
    int* r1 = (int*)malloc(sizeof(int) * length);
    int* r2 = (int*)malloc(sizeof(int) * length);
    for (i = 0; i < length; i++)
    {
        scanf("%d", &a1[i]);
        r2[i] = r1[i];
    }

    char qlog[] = "quicksort.log";
    FILE* fp = fopen(qlog, "w+");
    for (i = 0; i < length; i++)
    {
        if (i != 0)
            fprintf(fp, " ");
        fprintf(fp, "%d", r1[i]);
    }
    fprintf(fp, "\n");

    Quick_Sorting(r1, 0, length - 1, fp, length);
    fclose(fp);

    for (int i = 0; i < length; i++)
    {
        printf("%d", r1[i]);
        if (i < length - 1)
            printf(" ");
    }

    char hlog[] = "heapsort.log";
    fp = fopen(hlog, "w+");
    for (i = 0; i < length; i++)
    {
        if (i != 0)
            fprintf(fp, " ");
        fprintf(fp, "%d", r2[i]);
    }
    fprintf(fp, "\n");

    heap(r2, length, fp);
    fclose(fp);
    free(r1);
    free(r2);
    printf("\n");
    return 0;
}
