#include <iostream>
#include <vector> 

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int Wpos = 0;
        for (int Rpos = 0 ; Rpos < nums.size() ; Rpos++)
        {
            if ( nums[Rpos] != val )
            {
                nums[Wpos] = nums[Rpos];
                Wpos++;
            } 
            
        }

        return Wpos;
    }
};

int main() {
    Solution x; 
    
    std::vector<int> nums = {0, 1, 2, 2, 3, 5, 4, 2};
    int val = 2;
    
    int k = x.removeElement(nums, val);
    
    std::cout << "Count of valid elements (k): " << k << std::endl;
    std::cout << "Modified array (first " << k << " elements): [";
    for (int i = 0; i < k ; i++) {
        std::cout << nums[i] << (i == k - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
    return 0;
}
