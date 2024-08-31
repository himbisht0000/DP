class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> farthest_array;

        //if there is single or zero element
        if(nums.size() <= 1)
        return 0;


        //calculate farthest we can go with each index
        for(int i = 0 ; i < nums.size() ; i++)
        {
            farthest_array.push_back(i+nums[i]);
        }

        int curr_end = 0 , jumps = 0, farthest_index = 0;

        for(int i = 0; i < farthest_array.size(); i++)
        {
            farthest_index = max(farthest_index , farthest_array[i]);
            if(i == curr_end)
            {
                jumps++;
                curr_end = farthest_index;
                // if we have reached the last index break
                if(curr_end == nums.size() - 1)
                {
                    break;
                }
                
            }
        }

        return jumps;

    }
};
