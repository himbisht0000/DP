class Solution {
public:
    int prev_max(vector<int> nums ,  int index)
    {
        int ans  = 0;
        // check for all previous house except adjacent house
        for(int i = 0 ; i <  index - 1 ; i++)
        {
            ans = max(ans, nums[i]);
        }

        return ans;
    }

    int rob(vector<int>& nums) {
    
        int answer = 0;
        vector<int> copy_vector = nums;
        
        //edge case when there is asingle element vector
        if(nums.size() == 1)
        return nums[0];
        
        // remove the last element as we cannot include it
        nums.pop_back();

        for( int i = 0 ; i < nums.size() ; i++)
        {
            // check all the house before current and fix house with max value
            nums[i] = nums[i] + prev_max(nums , i); 
            // store max value found till now
            answer = max(nums[i], answer);
        }
        
        // we perform same opreation from last element to second element 
        // as last element was not included in earlier calculation
        reverse(copy_vector.begin() , copy_vector.end());
        copy_vector.pop_back();

        for( int i = 0 ; i < copy_vector.size() ; i++)
        {
            // check all the house before current and fix house with max value
            copy_vector[i] = copy_vector[i] + prev_max(copy_vector , i); 
            // store max value found till now
            answer = max(copy_vector[i], answer);
        }


        return answer;
    
    }
};
