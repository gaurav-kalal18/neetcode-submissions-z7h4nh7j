class Solution {
public:
    //sliding window type
    int maxProfit(vector<int>& prices) {
        int l = 0; // buy
        int r = 1; // sell
        int profit = 0;

        while (r < prices.size()) {
            if (prices[r] > prices[l]) {
                profit = max(profit, prices[r] - prices[l]);
            } else {
                l = r; // shift buy to smaller price
            }
            r++;
        }

        return profit;
    }
};

/*class Solution {
public://more greedy nd clean
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - mn);  //CURRENT-MIN SO FAR
            mn = min(mn, prices[i]);
        }

        return profit;
    }
};*/

/*class Solution {
public:
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
};*/

