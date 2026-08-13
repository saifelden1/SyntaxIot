#include <stdio.h>
#include <stdlib.h>

/**
 * Approach 1: Front-to-Back using an extra temp array
 * Time Complexity: O(m + n)
 * Space Complexity: O(m + n)
 */
void merge_front_to_back(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    (void)nums1Size;
    (void)nums2Size;

    int temp[m + n > 0 ? m + n : 1];
    int i = 0; // Pointer for nums1
    int j = 0; // Pointer for nums2
    int k = 0; // Pointer for temp array

    // Step 1: Compare from front to back and write smaller element to temp
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            temp[k] = nums1[i];
            i++;
        } else {
            temp[k] = nums2[j];
            j++;
        }
        k++;
    }

    // Step 2: Copy remaining elements from nums1 if any
    while (i < m) {
        temp[k] = nums1[i];
        i++;
        k++;
    }

    // Step 3: Copy remaining elements from nums2 if any
    while (j < n) {
        temp[k] = nums2[j];
        j++;
        k++;
    }

    // Step 4: Copy temp back into nums1
    for (int idx = 0; idx < m + n; idx++) {
        nums1[idx] = temp[idx];
    }
}

int main(void) {
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int m = 3;
    int nums2[3] = {2, 5, 6};
    int n = 3;

    printf("Front-to-Back Merge Test:\n");
    printf("Before: ");
    for (int idx = 0; idx < m + n; idx++) printf("%d ", nums1[idx]);
    printf("\n");

    merge_front_to_back(nums1, 6, m, nums2, 3, n);

    printf("After:  ");
    for (int idx = 0; idx < m + n; idx++) printf("%d ", nums1[idx]);
    printf("\n");

    return 0;
}
