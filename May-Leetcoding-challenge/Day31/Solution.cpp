class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        
        if(s1*s2==0)
            return s1+s2;
        
        int cache[s1+1][s2+1];
        
        for(int i=0;i<=s1;i++)
            cache[i][0] = i;
        
        for(int j=0;j<=s2;j++)
            cache[0][j] = j;
        
        for(int i=1;i<=s1;i++)
            for(int j=1;j<=s2;j++)
            {
                int left = cache[i-1][j] + 1;
                int down = cache[i][j-1] + 1;
                int left_down = cache[i-1][j-1];
                if(word1[i-1]!=word2[j-1])
                    left_down += 1;
                cache[i][j] = min(left, min(down, left_down));
            }
        
        return cache[s1][s2];
    }
};
