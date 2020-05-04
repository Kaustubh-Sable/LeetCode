class Solution {
public:
    int findComplement(int num) {
        if(num==0)
            return 1;
        
        string snum = "";
        int ans=0;
        
        while(num>1)
        {
            snum = (num%2==1?'0':'1') + snum;
            num /= 2;
        }
        
        int size=snum.size();
        for(int i=size-1;i>=0;i--)
        {
            ans += (snum[i]=='0'?0:1)*pow(2,size-1-i);
        }
        
        return ans;
    }
};
