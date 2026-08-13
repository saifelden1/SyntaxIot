#include <iostream>
#include <vector> 

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i]; 
            i--;                 
        } else {
            nums1[k] = nums2[j]; 
            j--;                 
        }
        k--;    
    }                 
    
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int m, n;
    
    std::cout << "Enter number of elements in nums1 (m): ";
    std::cin >> m;
    std::cout << "Enter number of elements in nums2 (n): ";
    std::cin >> n;

    // Allocate nums1 with space for m + n elements
    std::vector<int> nums1(m + n);
    std::vector<int> nums2(n);

    std::cout << "Enter " << m << " sorted numbers for nums1: ";
    for (int idx = 0; idx < m; idx++) {
        std::cin >> nums1[idx];
    }

    std::cout << "Enter " << n << " sorted numbers for nums2: ";
    for (int idx = 0; idx < n; idx++) {
        std::cin >> nums2[idx];
    }

    // Call the merge function
    merge(nums1, m, nums2, n);

    // Print the result
    std::cout << "Merged array: [";
    for (int idx = 0; idx < m + n; idx++) {
        std::cout << nums1[idx] << (idx == m + n - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    return 0;
}
