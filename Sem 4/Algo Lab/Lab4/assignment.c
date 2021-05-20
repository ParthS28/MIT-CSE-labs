#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min[1000], min_value = INT_MAX;
int opcount = 0;
void printCombinations(int r, int arr[r][r], int temp[r], int temp1[r], int l)
{
    int i, j;

    if (l == r)
    {

        int sum = 0, flag = 1;

        for (i = 0; i < r - 1; i++)
        {
            for (j = i + 1; j < r; j++)
            {

                if (temp1[i] == temp1[j])
                {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag == 1)
        {
            opcount++;
            for (j = 0; j < r; j++)
            {
                sum += temp[j];
                printf("%d ", temp[j]);
            }
            printf("->%d \n", sum);
        }

        if (sum < min_value && flag)
        {
            for (i = 0; i < r; i++)
            {
                min[i] = temp[i];
            }

            min_value = sum;
        }
    }

    else
    {
        for (i = 0; i < r; i++)
        {
            temp[l] = arr[i][l];
            temp1[l] = i;

            printCombinations(r, arr, temp, temp1, l + 1);
        }
    }
}
int main()
{
    int i, j, n;

    printf("Enter the Size of the Square Matrix:\n");
    scanf("%d", &n);

    int arr[n][n];

    printf("Enter Person vs Job Cost Matrix :\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }

    int temp[n];
    int temp1[n];
    printCombinations(n, arr, temp, temp1, 0);

    printf("The Minimum Cost Combination is : ");

    for (j = 0; j < n; j++)
        printf("%d ", min[j]);

    printf("\nThe Minimum Cost is : %d\n", min_value);
    printf("Opcount:%d\n", opcount);
    return 0;
}