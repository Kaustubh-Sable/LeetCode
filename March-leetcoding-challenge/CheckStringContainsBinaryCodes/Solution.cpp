class Solution {
    unordered_set<string> ms;
    void getAllCodeCombinations(string curr, int index, int k) {
        if(index==k) {
            ms.insert(curr);
            return ;
        }
        
        curr[index] = '0';
        getAllCodeCombinations(curr, index+1, k);
        curr[index] = '1';
        getAllCodeCombinations(curr, index+1, k);
    }
public:
    bool hasAllCodes(string s, int k) {        
        string initial = "";
        for(int i=0;i<k;i++)
            initial += "2";
        getAllCodeCombinations(initial, 0, k);
        
        for(int i=0;i+k<=s.size();i++) {
            ms.erase(s.substr(i,k));
        }
        
        return ms.empty();
    }
};
