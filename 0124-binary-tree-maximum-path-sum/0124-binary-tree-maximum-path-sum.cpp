class Solution {
public:
    int ans = INT_MIN;

    int m(TreeNode* root) {

        if (root == NULL)
            return 0;

        int l = max(0, m(root->left));
        int r = max(0, m(root->right));

        // Path passing through current node
        ans = max(ans, root->val + l + r);

        // Return only one side to parent
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        m(root);
        return ans;
    }
};