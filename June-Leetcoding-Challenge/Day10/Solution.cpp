class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int mid, l=0, r=nums.size()-1;
        
        while(l<=r)
        {
            mid = (l+r)/2;
            mid = mid<0? 0:mid;
            if(nums[mid]==target)
                return mid;

            if(l>=r)
            {
                if(target<nums[l])
                    return l;
                else
                    return l+1;
            }

            if(target<nums[mid])
                r = mid-1;
            else
                l = mid+1;
        }
        if(target<nums[l])
            return l;
        else
            return l+1;
    }
};
