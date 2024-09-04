class Solution {
public:
    bool isPanildrome(string s ,  int start, int end)
    {
        while(start<=end)
        {
            if(s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
    void solve(int start , string s, vector<string> temp , vector<vector<string>>& output)
    {
        if(start >= s.length())
        {
            output.push_back(temp);
            return;
        }


        for(int i = start ; i < s.length() ; i++)
        {
            if(isPanildrome(s ,start , i))
            {
                temp.push_back(s.substr(start, i - start + 1));
                solve(i + 1 ,s, temp,output);
                temp.pop_back();
            }
        }


    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> temp;
        solve(0,s,temp,output);
        return output;
    }
};
