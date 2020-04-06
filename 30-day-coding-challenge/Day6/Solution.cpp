class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> string_map;
        string sorted_string;
        
        for(int i=0;i<strs.size();i++)
        {
            sorted_string = strs[i];
            sort(sorted_string.begin(), sorted_string.end());
            string_map[sorted_string].push_back(strs[i]);            
        }
        
        vector<vector<string>> ans;
        for(auto ans_vec : string_map)
            ans.push_back(ans_vec.second);
        
        return ans;
    }
};
