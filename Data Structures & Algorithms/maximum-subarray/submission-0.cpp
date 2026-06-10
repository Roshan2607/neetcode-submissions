class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int best_start = 0;
        int best_end = 0;

        for (int i = 0; i < nums.size(); i++) {
            int current_sum = 0;
            for (int j = i; j < nums.size(); j++) {
                current_sum = current_sum + nums[j];
                
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    best_start = i;
                    best_end = j;
                }
            }
        }
        return max_sum;
    }
};
