class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
                
        if(n<2)
            return 0;
        
        int jumps = 1, maxPosition=nums[0], maxSteps=nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(i>maxSteps)
            {
                ++jumps;
                maxSteps = maxPosition;
            }
            if(i+nums[i]>maxPosition)
            {
                maxPosition = i+nums[i];
            }
        }
        
        return jumps;
    }
};
