#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> lut(amount+1);
        for(unsigned int i=0; i<lut.size(); i++)
            lut[i]=-2;
        return coinChangeHelper(coins, amount, lut);
    }
    
private:    
    int coinChangeHelper(vector<int>& coins, int amount, vector<int> &lut) 
    {
        if(amount<0) return -1;
        if(amount==0) return 0;
        if(lut[amount]!=-2) return lut[amount];
    
        int min=INT_MAX;
        for(unsigned int i=0; i<coins.size(); i++)
        {
            if(amount-coins[i]>=0)
            {
                int val = coinChangeHelper(coins, amount-coins[i], lut);
                if(val>=0)
                    min = min<val?min:val;
            }
        }
        if(min!=INT_MAX)
            lut[amount]=min+1;
        else 
            lut[amount]=-1;
    
        return lut[amount];
    }
};

int main()
{
    class Solution sol;
    vector<int> coins(3);
    vector<int> coins1(1);
    coins = {1, 2, 5};
    coins1 = {2};
    int amount = 11;
    int amount1 = 3;
    int min_coins;

    min_coins = sol.coinChange(coins, amount);
    cout << min_coins << endl;
    
    min_coins = sol.coinChange(coins1, amount1);
    cout << min_coins << endl;
    
    return 0;
}

