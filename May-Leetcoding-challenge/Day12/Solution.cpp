class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        /*
        int a=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            a = a^nums[i];
        }
        
        return a;
        */
        
        int left=0, right=nums.size()-1, mid;
        
        while(left<right)
        {
            mid = (left+right)/2;
            bool halvesEven = (right-mid)%2==0;
            
            if(nums[mid]==nums[mid+1])
            {
                if(halvesEven)
                    left = mid + 2;
                else
                    right = mid - 1;
            }
            else if(nums[mid]==nums[mid-1])
            {
                if(halvesEven)
                    right = mid - 2;
                else
                    left = mid + 1;
            }
            else
                return nums[mid];
        }
        
        return nums[left];
    }
};
