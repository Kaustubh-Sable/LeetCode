class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int max = 0, n=matrix.size(), m=matrix[0].size(), count=0;
        
        vector<vector<int>> cache(n, vector<int>(m, 0));
                
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                {
                    if(matrix[i][j]==1)
                    {
                        cache[i][j] = 1;
                        count++;
                    }
                } else if(matrix[i][j]==1)
                {
                    cache[i][j] = min(min(cache[i][j-1], cache[i-1][j]), cache[i-1][j-1]) + 1;
                    count+=cache[i][j];
                }
                if(cache[i][j] > max)
                    max = cache[i][j];
            }
        }
        
        return count;
    }
};
