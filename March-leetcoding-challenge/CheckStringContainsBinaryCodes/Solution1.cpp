class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> ms;
        for(int i=0;i+k<=s.size();i++) {
            ms.insert(s.substr(i,k));
        }
        
        return ms.size()==pow(2,k);
    }
};
