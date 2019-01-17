#include <stdio.h>

#include "test.h"
#include "lab12_2_lib.h"

int main()
{
    int arr1[] = {0, 2, 3, 4};
    int arr2[] = {3, 4, 0, 2};
    int arr3[] = {0, 6, 1, 6, 4};
    int arr4[] = {0, 1, 4};
    int arr5[] = {3, 5, 6, 7};
    int arr6[] = {1, 2, 3};
    int arr7[] = {2, 3, 1};

    printf("Test shift array:\n");
    test_shift_array("Test correct:", arr1, 4, 2, arr2);
    test_shift_array("Test k > n:", arr6, 3, 4, arr7);
    printf("\nTest square numbers:\n");
    test_square_numbers("Test correct:", arr3, 5, arr4, 3);
    test_square_numbers("Test with no squares:", arr5, 4, arr5, 0);

    return 0;
}

/**
 * Compare two arrays
 * @param a1 - array 1
 * @param n1 - size of array 1
 * @param a2 - array 2
 * @param n2 - size of array 2
 * @return 1 if arrays are identical
 */
int compare_arrays(const int *a1, int n1, const int *a2, int n2)
{
    int flag = 1;

    if (n1 != n2)
        flag = 0;

    for (int i = 0; i < n2 && flag; i++)
        if (a1[i] != a2[i])
            flag = 0;

    return flag;
}

void test_shift_array(char msg[], int arr[], int n, int k, int arr_res[])
{
    printf("%-30s", msg);
    shift_array(arr, n, k);
    if (compare_arrays(arr, n, arr_res, n))
        printf("Passed\n");
    else
    {
        printf("Failed\n");
        print_arr(arr, n);
        printf("|");
        print_arr(arr_res, n);
        puts("");
    }

}

void test_square_numbers(char msg[], int arr[], int n, int arr_res[], int n_res)
{
    printf("%-30s", msg);
    int result_n = 0;
    int *result = square_numbers(arr, n, &result_n);

    if (compare_arrays(result, result_n, arr_res, n_res))
        printf("Passed\n");
    else
    {
        printf("Failed\n");
        print_arr(result, result_n);
        printf("|");
        print_arr(arr_res, n_res);
    }
}
