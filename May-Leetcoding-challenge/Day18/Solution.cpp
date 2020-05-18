class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        
        vector<int> s2_count(26, 0);
        vector<int> s1_count(26, 0);
        
        for(int i=0;i<s1.size();i++)
            s1_count[s1[i]-'a']++;
        
        for(int i=0;i<s1.size()-1;i++)
            s2_count[s2[i]-'a']++;
        
        int i=0, j=s1.size()-1;
        while(j<s2.size())
        {
            s2_count[s2[j]-'a']++;
            if(s1_count==s2_count)
                return true;
            s2_count[s2[i]-'a']--;
            i++;
            j++;            
        }
        
        return false;
    }
};
