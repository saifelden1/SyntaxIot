#include <iostream>
#include <vector> 

class Solution {
public:
    int removeElement(std::vector<int>& nums) {
        int Wpos=0;
        for (int x = 0 ; x < (int)nums.size() ; x++)
        {

            bool Dup = false;

            for ( int i = x - 1 ; i >=0 ; i--)
            {
                if (nums[x] == nums[i])
                {
                    Dup = true;
                    break;
                }
            }
            
            if (!Dup)
            {
                nums[Wpos] = nums[x];
                Wpos++;

            }
            
        }

        return Wpos;
    }
};

int main() {
    Solution x; 
    
    std::vector<int> nums = {0, 4, 2, 4, 5, 4, 4, 2};
    
    int k = x.removeElement(nums);
    
    std::cout << "Size of the new element" << k << std::endl;
    std::cout << "Modified array (first " << k << " elements): [";
    for (int i = 0; i < k ; i++) {
        std::cout << nums[i] << (i == k - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
    return 0;
}
