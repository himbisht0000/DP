class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max_product = INT_MIN, current_product = 1;
        // find product of all possible sub array
        for(int i = 0 ; i < nums.size() ; i++)
        {   
            current_product *= nums[i];
            max_product = max(max_product , current_product);
            
            // reset current_sum to avoid whole product to become zero
            if(current_product == 0)
            {
                current_product = 1;
            }
        }

        current_product = 1;
        // find product of all possible left sub array
        for(int i = nums.size() - 1 ; i >= 0 ; i-- )
        {   
            current_product *= nums[i];
            max_product = max(max_product , current_product);
            
            // reset current_sum to avoid whole product to become zero
            if(current_product == 0)
            {
                current_product = 1;
            }

        }

        return max_product;
    }
};
