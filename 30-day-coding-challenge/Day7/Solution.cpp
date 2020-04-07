class Solution {
public:
    int countElements(vector<int>& arr) {
        int ans=0;
        
        sort(arr.begin(),arr.end());
        
        int count = 1, prev = arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==arr[i-1])
            {
                count++;
                continue;
            }
            
            if(arr[i]==arr[i-1]+1)
                ans+=count;
            prev = arr[i];
            count = 1;
        }
        
        return ans;
    }
};
