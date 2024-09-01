class Solution {
public:
    bool solve(int a, int b , int i , string s1 , string s2, string s3)
    {
        bool x = false ,y = false;
        bool flag = false;

        // if  se have traversed  both s1 and s2 that means s3 must be formed by s1 and s2
        if(s1.size() == a && s2.size() == b)
        {
            return true;
        }

        // if current element of s1 matches with s3 
        if(s1[a] == s3[i] && a < s1.size())
        {
            x = solve(a+1 , b , i + 1 , s1, s2, s3);
            flag = true;
        }

        // if current element of s1 matches with s3 
        if(s2[b] == s3[i] && b < s2.size())
        {
            y = solve(a , b+1 , i + 1 , s1, s2, s3);
            flag = true;
        }

        // if s1 and s2 both could both with s3 then its failure
        if(!flag)
        {
            return false;
        }
        
        
        return x || y;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        if( (s1.size() + s2.size()) != s3.size())
        return false;

        return solve(0,0,0,s1,s2,s3);
    }
};
