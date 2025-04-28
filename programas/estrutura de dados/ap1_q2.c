#include <stdio.h>

// invertendo arr 
/*
for ( int i = 0, j = ARRLEN-1; i < j; i++, j-- )
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
} 
*/

int rec_arr_inv(int arr[], int i, int j)
{
    if (i<j) 
        return 0;

    int temp;
    temp = arr[i];
    arr[i] = arr[j-1];
    arr[j-1] = temp;
    
    rec_arr_inv(arr, i-1, j+1);
}


#define ARR_SIZE 5
int main()
{
    int arr[ARR_SIZE] = { 0, 1, 2, 3, 4 };
    rec_arr_inv(arr, ARR_SIZE, 0);

    for ( int i = 0; i < ARR_SIZE; i++ )
        printf("%d\n", arr[i]);

    return 0;
}