#include <iostream>
#include <vector> 

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num; // Rule 1: Claim empty throne
            }
            
            if (num == candidate) {
                count++; // Rule 2: Ally joins
            } else {
                count--; // Rule 3: Enemy fights and both die
            }
        }
        return candidate; // Survivor wins
    }
};

int main() {
    Solution x; 
    
    // Updated test array: size is 9, and '4' appears 5 times (which is > 9/2)
    std::vector<int> nums = {4, 4, 2, 4, 5, 4, 4, 2, 4};
    
    // Fixed: Call majorityElement instead of removeElement
    int majority = x.majorityElement(nums);
    
    // Fixed: Print the majority element directly
    std::cout << "The majority element is: " << majority << std::endl;
    
    return 0;
}