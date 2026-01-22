class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while (!is_sorted(nums.begin(), nums.end())) {
            int mn = 1E9;
            int pos = -1;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (mn > nums[i] + nums[i + 1]) {
                    mn = nums[i] + nums[i + 1];
                    pos = i;
                }
            }

            nums[pos] += nums[pos + 1];
            nums.erase(nums.begin() + pos + 1);

            ans++;
        }
        return ans;
    }
};