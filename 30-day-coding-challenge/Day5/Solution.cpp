class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<1)
            return 0;
        
        int low, high, profit=0;
        low=high=0;
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[low+1]<=prices[low])
                low = high = (low+1);
            if(prices[high]<prices[i])
                high = i;
            else
                if(low<high)
                {
                    profit += (prices[high]-prices[low]);
                    low = high = i;
                }
        }
        if(high==prices.size()-1 && low<high)
        {
            profit += (prices[high]-prices[low]);
        }
        return profit;
    }
};
