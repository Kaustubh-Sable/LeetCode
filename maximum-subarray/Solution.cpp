class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cache[nums.size()],sum,max=nums[0];
        int i;
        cache[0] = nums[0];
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]+cache[i-1]>nums[i])
                sum = nums[i]+cache[i-1];
            else
                sum = nums[i];
            if(sum>max)
                max=sum;
            cache[i]=sum;
        }
        return max;
    }
};
