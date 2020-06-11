/*
 * leet_0004_median_of_two_sorted_arrays.c
 *
 *  Created on: May 31, 2020
 *      Author: lrs
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b)  ((a) < (b)) ? (a) : (b)
#define MAX(a, b)  ((a) > (b)) ? (a) : (b)

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int i_min = 0, i_max = nums1Size - 1;
    int i,j;
    int left_max, right_min;
    double result;
    int *tmp;
    int tmp_size;

    if (nums1Size > nums2Size) {
        tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
        tmp_size = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tmp_size;
    }

    if (nums1Size == 0 && nums2Size == 0) {
        return 0;
    } else if (nums1Size == 0) {
        if (nums2Size % 2 == 1) {
            return nums2[nums2Size / 2];
        } else {
            return (double)(nums2[nums2Size / 2] + nums2[(nums2Size/2) - 1]) / 2;
        }
    }

    i_min = 0;
    i_max = nums1Size - 1;

    while (i_min <= i_max) {
        i = (i_min + i_max) / 2;
        j  = (nums1Size + nums2Size) / 2 - i;

        if (j >= 1 && nums2[j - 1] > nums1[i]) {
            i_min = i + 1;
        } else if (j < nums2Size  && i >= 1&& nums1[i - 1] > nums2[j]) {
            i_max = i - 1;
        } else {
            break;
        }
    }


    if (i == nums1Size - 1 && i_min > i_max) {
        i += 1;
        j -= 1;
    }

    if (i == 0) {
        left_max = nums2[j - 1];
    } else if (j == 0) {
        left_max = nums1[i - 1];
    } else {
        left_max = MAX(nums1[i - 1], nums2[j - 1]);
    }

    if (i == nums1Size) {
        right_min = nums2[j];
    } else if (j == nums2Size) {
        right_min = nums1[i];
    } else {
        right_min = MIN(nums1[i], nums2[j]);
    }

    if ((nums1Size + nums2Size) % 2 == 1) {
        return right_min;
    } else {
        return (double)(left_max + right_min) / 2;
    }
}

int main(void) {
    int arr_1[] = {1, 2, 3, 5, 6, 7};
    int arr_2[] = {4};
    double result = findMedianSortedArrays(arr_1, sizeof(arr_1)/ sizeof(arr_1[0]), arr_2, sizeof(arr_2)/ sizeof(arr_2[0]));

    fprintf(stderr, "---Function: %s ---- Line: %d result: %f\n", __FUNCTION__, __LINE__, result);
}
