class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if( (s1.size() + s2.size()) != s3.size())
        return false;

        bool a,b;
        bool matrix[s1.size() + 1][s2.size() + 1];
        memset(matrix, false, sizeof(bool) * (s1.size()+1) * (s2.size() + 1));
        
        //this always be true 
        matrix[s1.size()][s2.size()] = true;

        //fill last row 
        for(int i = s2.size() - 1 ; i >=0 ; i-- )
        {   
            if(s2[i] == s3[s1.size() + i])
            {
                matrix[s1.size()][i] = matrix[s1.size()][i+1];
            }
        }

        //fill last column
        for(int i = s1.size() - 1 ; i >=0 ; i-- )
        {
            if(s1[i] == s3[s2.size() + i])
            {
                matrix[i][s2.size()] = matrix[i+1][s2.size()];
            }
        }

        //fill remainning matrix
        for(int i = s1.size()-1 ; i >=0 ; i--)
        {
            
            for(int j = s2.size()-1 ; j>=0 ; j--)
            {
                a = b = false;
                //check if either character from s1 or s2 macthes with s3
                if(s1[i] == s3[i+j])
                a = matrix[i+1][j];
                
                if(s2[j] == s3[i+j])
                b = matrix[i][j+1];

                matrix[i][j] = a||b;
            }
        }
        
        return matrix[0][0];
    }
};
