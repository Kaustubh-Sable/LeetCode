class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0], count=1, n=nums.size();
        unordered_map<int,int> umap;
        
        for(int i=0;i<n;i++)
        {
            umap[nums[i]]++;
            if(umap[nums[i]]>n/2)
                break;
        }
        
        for (auto i : umap)
        {
            if(i.second>count)
            {
                count = i.second;
                ans = i.first;
            }
        }
        
        return ans;
    }
};
