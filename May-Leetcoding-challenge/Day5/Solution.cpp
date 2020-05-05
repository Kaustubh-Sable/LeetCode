class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hashm;
        int i, temp;
        unordered_map<char,int>::iterator it;
        for(i=0;i<s.size();i++)
        {
            it = hashm.find(s[i]);
            if(it != hashm.end())
            {
                temp = it->second;
                hashm[s[i]] = temp+1;
            }
            else
                hashm[s[i]] = 1;
        }
        for(i=0;i<s.size();i++)
        {
            if(hashm.at(s[i])==1)
                return i;
        }
        return -1;
    }
};
