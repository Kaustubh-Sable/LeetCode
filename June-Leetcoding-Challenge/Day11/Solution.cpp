class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_index=0, two_index=nums.size()-1, curr_index=0;
        
        while(curr_index<=two_index)
        {
            if(nums[curr_index]==0)
            {
                int temp = nums[curr_index];
                nums[curr_index] = nums[zero_index];
                nums[zero_index] = temp;
                
                zero_index++;
                curr_index++;
            }
            else if(nums[curr_index]==2)
            {
                int temp = nums[curr_index];
                nums[curr_index] = nums[two_index];
                nums[two_index] = temp;
                
                two_index--;
            }
            else
                curr_index++;
        }
    }
};
