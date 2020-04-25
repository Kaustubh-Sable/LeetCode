class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0, n = nums.size();
        
        if(n==1)
            return true;
        
        for(int i=0;i<n;i++)
        {
            if(i>max)
                return false;
            if(i+nums[i]>max)
            {
                max = i+nums[i];
            }
        }
        
        return true;
    }
};
