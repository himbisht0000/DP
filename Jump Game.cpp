class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int i , max_index = 0;
        // tarverse the nums array and update max_index
        while(i < nums.size() && i <= max_index)
        {
            max_index = max(i + nums[i] , max_index);
            if(max_index >= ( nums.size() - 1 ))
            {
                return true;
            }
            i++;
        }

        return false;
    }
};
