class Solution {
public:
    bool is_valid(string s , int i)
    {
        string data[26] = {"1" ,"2", "3", "4" ,"5" , "6" , "7" ,"8",
        "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
        "20", "21", "22", "23", "24", "25", "26"};

        for(int j = 0; j < 26 ; j++)
        {
            if(data[j] == s.substr(i,2))
            {
                return true;
            }
        }

        return false;
    }

    int numDecodings(string s) {
        
        int output = 0;
        int arr[s.size()];
        memset(arr , 0 , sizeof(arr));

        if(s[s.size() - 1] != '0')
        arr[s.size()-1] = 1;
        
        if(s.size() == 1)
        return arr[0];

        if(s[s.size() - 2] == '0')
        arr[s.size()-2] = 0;
        else
        {
            if(is_valid(s,s.size() -2)  )
            arr[s.size()-2] = arr[s.size()-1] + 1;
            else
            arr[s.size()-2] = arr[s.size()-1] ;
        }


        for(int i = s.size() - 3 ; i>=0 ; i--)
        {
            if(s[i] == '0')
            {
                arr[i] = 0;
                continue;
            }

            arr[i] += arr[i+1];

            if(is_valid(s,i))
            arr[i] += arr[i+2];
        }
        return arr[0];
        
    }
};

/* Recursive code */
/*
class Solution {
public:
    bool is_valid(string s , int i)
    {
        string data[26] = {"1" ,"2", "3", "4" ,"5" , "6" , "7" ,"8",
        "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
        "20", "21", "22", "23", "24", "25", "26"};

        for(int j = 0; j < 26 ; j++)
        {
            if(data[j] == s.substr(i,2))
            {
                return true;
            }
        }

        return false;
    }

    int solve(string s, int i)
    {
        int a = 0 , b = 0;

        if(s[i] == '0')
        return 0;

        if( i >= (s.size() -1 ))
        return 1;

        

        a = solve(s,i+1);
        
        if(is_valid(s,i))
        {
            b = solve(s, i +2);
        }

        //if(a == -1 || b == -1)
        //{
       //     return -1;
       // }

        return (a+b);
    }
    int numDecodings(string s) {
        
        int output = 0;
        int arr[s.size()];
        memset(arr , 0 , sizeof(arr));

        if(s[s.size() - 1] != '0')
        arr[s.size()-1] = 1;
        
        if(s.size() == 1)
        return arr[0];

        if(s[s.size() - 2] == '0')
        arr[s.size()-2] = 0;
        else
        {
            if(is_valid(s,s.size() -2)  )
            arr[s.size()-2] = arr[s.size()-1] + 1;
            else
            arr[s.size()-2] = 1;
        }


        for(int i = s.size() - 3 ; i>=0 ; i--)
        {
            if(s[i] == '0')
            {
                arr[i] = 0;
                continue;
            }

            arr[i] += arr[i+1];

            if(is_valid(s,i))
            arr[i] += arr[i+2];
        }
        
        //output = solve(s, 0);
        
        //if(output == -1)
        //output = 0;
        for(int i = 0 ;i < s.size();i++)
        {
            cout<<arr[i]<<" ";
        }
        //return output;
        return arr[0];
        
    }
};

*/
