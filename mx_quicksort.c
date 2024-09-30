#include "libmx.h"

static int swap_count = 0;

static int partition(char **arr, int left, int right) 
{
    int mid = left + (right - left) / 2;
    int pivot_length = mx_strlen(arr[mid]);
    int i = left, j = right;

    mx_swap(arr[mid], arr[right]);
    swap_count++;

    while (i < j) 
    {
        while (i < j && mx_strlen(arr[i]) <= pivot_length) {
            i++;
        }
        while (i < j && mx_strlen(arr[j]) > pivot_length) {
            j--;
        }
        if (i < j) {
            mx_swap(arr[i], arr[j]);
            swap_count++;
        }
    }

    mx_swap(arr[i], arr[right]);
    swap_count++;

    return i;
}

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) {
        return -1;
    }
    if (left < right) 
    {
        int pivot_index = partition(arr, left, right);
        mx_quicksort(arr, left, pivot_index - 1);
        mx_quicksort(arr, pivot_index + 1, right);
    }
    return swap_count;
}

