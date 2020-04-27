class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()<=0)
            return 0;
        
        vector<vector<int>> cache(matrix.size() , vector<int> (matrix[0].size(), 0));
        int max = 0;
        
        for (int i = 0; i<cache.size(); i++) 
        {
            for (int j=0; j<cache[0].size(); j++) 
            {
                if (i==0 || j==0) 
                {
                    cache[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else if (matrix[i][j]=='1') 
                {
                    cache[i][j] = min(min(cache[i][j-1], cache[i-1][j]), cache[i-1][j-1]) + 1;
                }
        
                if (cache[i][j] > max) 
                    max = cache[i][j];
            }
        }
        
        return max*max;
    }
};
