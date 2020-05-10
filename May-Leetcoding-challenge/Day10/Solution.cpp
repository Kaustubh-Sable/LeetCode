class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N==1 && trust.size()==0)
            return 1;
        if(N<2 || trust.size()<N-1)
            return -1;
        
        unordered_set<int> s;
        int i,n=trust.size();
        
        for(i=0;i<n;i++)
            s.insert(trust[i][0]);
        
        int sum=0;
        for(int i:s)
            sum += i;
        
        int missing_num = ((N*(N+1))/2)-sum;
        if(missing_num<1 || missing_num>N)
            return -1;
        
        int count=0;
        
        for(i=0;i<n;i++)
            if(trust[i][1]==missing_num)
                count++;
        
        if(count==N-1)
            return missing_num;
        else
            return -1;
    }
};
