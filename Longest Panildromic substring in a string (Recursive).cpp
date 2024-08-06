class Solution {
public:
    int start = 0 , end = -1;
    int solve(string s , int i, int j)
    {
        //if string has single charcter then if is panildrome
        if(i == j)
        {
            if( ( j - i ) > (end - start ))
            start = end = i;
            return 1;
        }
        else if( i == (j - 1) )
        {   //string string has two character then check if both character are equal or not
            //If character are equal then it is paniladrome simply save i and j
            if(s[i] == s[j])
            {
              if( ( j - i ) > (end - start ))
              {
                start = i;
                end = j;
              }
              return 1;
            }
            //if chacter are not equal then we process the remainning character
            //for example : in string "ac" 'a' or 'c' is a panildrome
        }

        //two character are equal then check string further 
        // if other middle chacters are also panildrome or not
        if(s[i] == s[j])
        {
            if(solve( s , i+1 , j-1) == 1)
            {
                if( ( j - i ) > (end - start ))
                {
                    start = i ;
                    end = j;
                }
                return 1;
            }
        }

        //check remainning string for panildrome
        solve(s , i+1 , j);
        solve(s , i , j-1);
        // return 0 as thier was no equal characters
        return 0;
    }
    string longestPalindrome(string s) {
        solve(s , 0 , s.length()-1);
        return s.substr(start,end - start + 1);
    }
};
