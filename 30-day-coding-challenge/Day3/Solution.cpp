class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum,max=nums[0];
        int i;
        int cum_sum = nums[0];
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]+cum_sum>nums[i])
                sum = nums[i]+cum_sum;
            else
                sum = nums[i];
            if(sum>max)
                max=sum;
            cum_sum=sum;
        }
        return max;
    }
};
