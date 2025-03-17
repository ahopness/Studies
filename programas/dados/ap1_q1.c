#include <stdio.h>

int rec_arr_count(int arr_c[], int arr_v)
{
    if (arr_v > 0)
        return arr_c[arr_v] + rec_arr_count(arr_c, arr_v-1);
    else
        return 0;
}

#define ARR_SIZE 5
int main()
{
    int arr[ARR_SIZE] = { 0, 1, 2, 3, 4 };
    printf("%d\n", rec_arr_count(arr, ARR_SIZE));

    return 0;
}