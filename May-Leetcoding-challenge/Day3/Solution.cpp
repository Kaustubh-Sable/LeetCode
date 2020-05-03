class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rp=0, mp=0, msize=magazine.size(), rsize=ransomNote.size();
        vector<int> count(26,0);
        
        for(int i=0;i<rsize;i++)
        {
            count[ransomNote[i]-'a']++;
        }
        
        for(int i=0;i<msize;i++)
        {
            count[magazine[i]-'a']--;
        }
        
        for(int i=0;i<26;i++)
        {
            if(count[i]>0)
                return false;
        }
        
        return true;
    }
};
