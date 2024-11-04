
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        // mountain should minimum have 3 vertices
        if(arr.size() < 3)
        return 0;

        int slope[arr.size()-1];
        memset(slope,0,sizeof(slope));

        int i = 0;
        int length = arr.size()-1;
        int max_output = 0;
        bool first_one = true;
        bool zero = false;
        int left = 0;

        for(i = 0; i < length ; i++)
        {
            if(arr[i] < arr[i+1])
            slope[i] = 1;
            else if(arr[i] > arr[i+1])
            slope[i] = 0;
            else
            slope[i] = 2;
        }

        i = 0 ;
        while( i < length)
        {
            
            if(slope[i]!=1 && max_output == 0 && first_one == true)
            {
                i++;
            }
            else
            {
                if(slope[i] == 1 && zero == false)
                {   
                    
                    if(first_one == true)
                    {
                        left = i;
                        first_one = false;
                    }
                    i++;
                }
                else if( (slope[i] == 0) && (first_one == false) )
                {
                    
                    i++;
                    zero = true;
                    cout<<i<<endl;
                }
                else if(zero)
                {
                    zero = false;
                    max_output = max(max_output , i - left + 1);
                    first_one = true;
                }
                else
                {
                    first_one = true;
                    zero = false;
                    i++;
                }

            }

        }

        if(zero)
        {
            max_output = max(max_output , i - left + 1);
        }

        return max_output;
    }
};
