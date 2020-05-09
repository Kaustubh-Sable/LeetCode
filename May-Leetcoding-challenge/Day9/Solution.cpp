class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return true;
        
        int left=1, right=num/2, mid;
        
        while(left<=right)
        {
            mid = (left+right)/2;
            
            if(num%mid==0 && mid==num/mid)
                return true;
            
            if(mid>=num/mid)
                right = mid-1;
            else
                left = mid+1;                
        }
        
        return false;
    }
};
