class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ts = t.size();
        int ss = s.size();
        if(ss>ts)
            return false;
        if(ss==0)
            return true;
        
        int j=0;
        
        for(int i=0;i<ts;i++)
        {
            if(t[i]==s[j])
            {
                j++;
                if(j==ss)
                    return true;
            }
        }
        
        return false;
    }
};
