class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> umap;
        umap[0] = -1;
        int max = 0, count = 0, temp;
        
        for(int i=0;i<nums.size();i++)
        {
            count += (nums[i]==1?1:-1);
            
            if(umap.find(count)!=umap.end())
            {
                temp = i - umap[count];
                if(temp>max)
                {
                    max = temp;
                }
            }
            else
            {
                umap[count] = i;
            }
        }
        
        return max;
    }
};
