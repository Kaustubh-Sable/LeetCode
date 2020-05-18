class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        if(p.size()>s.size())
            return ans;
        
        vector<int> s_count(26, 0);
        vector<int> p_count(26, 0);
        
        for(int i=0;i<p.size();i++)
            p_count[p[i]-'a']++;
        
        for(int i=0;i<p.size()-1;i++)
            s_count[s[i]-'a']++;
        
        int i=0, j=p.size()-1;
        while(j<s.size())
        {
            s_count[s[j]-'a']++;
            if(p_count==s_count)
                ans.push_back(i);
            s_count[s[i]-'a']--;
            i++;
            j++;            
        }
        
        return ans;
    }
};
