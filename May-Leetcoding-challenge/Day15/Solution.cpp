// Sub-optimal solution

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum,max=A[0];
        int i, n=A.size(), temp = A[0], left=0;
        
        bool allPositive = A[0]>=0?true:false;
        
        for(i=1;i<2*n;i++)
        {
            if(A[i%n]<0)
                allPositive = false;
            
            if(i==n && allPositive)
                return sum;
            
            if(A[i%n]+temp>A[i%n] && left!=i%n)
                sum = A[i%n]+temp;
            else
            {
                if(left==i%n)
                    i = left + 1;
                sum = A[i%n];
                left = i%n;
            }
            if(sum>max)
                max=sum;
            temp=sum;
        }
        return max;
    }
};
