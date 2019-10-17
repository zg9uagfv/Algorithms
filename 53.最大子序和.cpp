class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        if (0x00 == length) return 0x00;
        int dp[length]={0x00}, i = 0x01;
        dp[0] = nums[0];
        int max = nums[0];
        for(; i < length; ++i) {
            if (dp[i-1]+nums[i] <= nums[i]) {
                dp[i] = nums[i];
            } else {
                dp[i] = dp[i-1] + nums[i];
            }
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};
