class Solution {
public:
//MY SOLUTION
    int maxProfit(vector<int>& prices) {

        int r=0,pr=0,buy=0,sell=0;
        int n=prices.size();
        buy=prices[r];
        r++;
        while(r<n)
        {
            if(prices[r]>buy)
            {
                sell=prices[r];
                pr=max(pr,sell-buy);
                
                
            }

            else
            buy=prices[r];

            r++;
        }
        
        if(pr<0)
        return 0;

        return pr;
    }
};