class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> count;
        for(auto num:nums)
        {
            count[num]++;
        }
        
        for(auto ele:count)
            if(ele.second==1)
                return ele.first;
        
        return -1;
    }
};
