#include <stdio.h>

#define SIZE 3

void init_arr(int[][SIZE]);
void init_row_sep(char[]);
void print_box(int[][SIZE]);

int main()
{
    int arr2[SIZE][SIZE];
    init_arr(arr2);
    char arr[SIZE][SIZE];
    print_box(arr2);
    return 0;
}

void print_box(int arr[][SIZE])
{
    int last = SIZE - 1;
    char row_sep[100] = "";
    init_row_sep(row_sep);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // Tab in start of each line
            if (j % SIZE == 0)
                printf("\t ");
            if (arr[i][j] < 10 && SIZE > 3)
                printf("  %d ", arr[i][j]);
            else
                printf(" %d ", arr[i][j]);
            if (j % SIZE != last)
                printf("|");
        }
        if (i % SIZE != last)
            printf("\n\t%s\n", row_sep);
    }
}

void init_arr(int arr[][SIZE])
{
    int k = 1;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            arr[i][j] = k;
            k++;
        }
    }
}

void init_row_sep(char str[])
{
    int loop;
    if (SIZE > 3)
        loop = (5 * SIZE) + 1;
    else
        loop = 13;

    for (int j = 0; j <= loop; j++)
        str[j] = '-';
}