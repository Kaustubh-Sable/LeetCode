class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> ms;
        int total_comb = pow(2,k);
        for(int i=0;i+k<=s.size();i++) {
            ms.insert(s.substr(i,k));
            if(ms.size()==total_comb)
                return true;
        }
        
        return false;
    }
};
