class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max_val = amount + 1;
        vector<int> dp(amount + 1, max_val);

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                // If the current coin is less than or equal to the current amount 'i'
                if (coins[j] <= i) {
                    // Update dp[i] with the minimum coins needed
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        if (dp[amount] > amount) {
            return -1;
        }
        
        return dp[amount];
    }
};
