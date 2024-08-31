class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0 , end = 0;
        int current_sum = 0;
        int max_sum = nums[0];
        int i;
        //check if all the elements are negative
        for(i = 1; i < nums.size() ; i++)
        {
            max_sum = max ( max_sum , nums[i]);
            if(nums[i] >= 0)
            break;
        }

        if(i == nums.size())
        {
            return max_sum;
        }
        else
        {
            max_sum = 0;
        }

        while(end < nums.size())
        {
            current_sum += nums[end];
            max_sum = max(max_sum , current_sum);
            while(current_sum < 0)
            {
                current_sum -= nums[start];
                start++;
            }
            end++;
            
        }

        return max_sum;
    }
};
