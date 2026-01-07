/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    const int P = 1E9 + 7;
    int tot = 0;
    long long ans = 0;

    int sum(TreeNode *x) {
        if (x == nullptr) {
            return 0;
        }
        return sum(x->left) + sum(x->right) + x->val;
    }

    int dfs(TreeNode *x) {
        if (x == nullptr) {
            return 0;
        }
        int sub = dfs(x->left) + dfs(x->right) + x->val;
        ans = std::max(ans, 1LL * (tot - sub) * sub);
        return sub;
    }

    int maxProduct(TreeNode* root) {
        tot = sum(root);
        dfs(root);
        ans %= P;
        return ans;
    }
};