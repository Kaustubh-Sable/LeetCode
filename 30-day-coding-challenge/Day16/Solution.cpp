class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                lo+=1;
            }
            else
            {
                lo-=1;
            }
            
            if(s[i]!=')')
            {
                hi+=1;
            }
            else
            {
                hi-=1;
            }
            
            if(hi<0)
                break;
            
            if(lo<0)
                lo = 0;
        }
        
        return lo==0;
    }
};
