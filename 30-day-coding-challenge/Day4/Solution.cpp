class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j,n=nums.size(),temp;
        while(i<n && nums[i]!=0)
            i++;
        j = i+1;
        while(i<j && j<n)
        {
            while(j<n && nums[j]==0)
                j++;
            if(j==n)
                break;
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j++;
        }
    }
};
