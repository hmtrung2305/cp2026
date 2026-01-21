class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        
        std::vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                int j = 0;
                ans[i] = nums[i];
                while (ans[i] >> j & 1) {
                    j++;
                }
                ans[i] ^= (1 << j) - 1;
                ans[i] ^= (1 << (j - 1)) - 1;
            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};