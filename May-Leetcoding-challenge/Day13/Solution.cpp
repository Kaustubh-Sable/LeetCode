class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> s;
        
        for(int i=0;i<num.size();i++)
        {
            while(s.size()>0 && k>0 && s.back()>num[i])
            {
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }
        
        for(int i=0;i<k;i++)
            s.pop_back();
        
        string ans = "";
        bool leadingZero = true;
        
        for(int i=0;i<s.size();i++)
        {
            if(leadingZero && s[i]=='0')
                continue;
            leadingZero = false;
            ans+=s[i];
        }
        
        return ans.size()==0?"0":ans;
    }
};
