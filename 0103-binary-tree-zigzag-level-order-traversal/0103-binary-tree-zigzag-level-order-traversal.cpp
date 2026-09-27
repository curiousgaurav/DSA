class Solution {
public:

    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left),
                       height(root->right));
    }

    void nthLevel(TreeNode* root, int n, vector<int>& ans) {
        if (root == NULL)
            return;

        if (n == 1) {
            ans.push_back(root->val);
            return;
        }

        nthLevel(root->left, n - 1, ans);
        nthLevel(root->right, n - 1, ans);
    }

    void nthLevel2(TreeNode* root, int n, vector<int>& ans) {
        if (root == NULL)
            return;

        if (n == 1) {
            ans.push_back(root->val);
            return;
        }

        nthLevel2(root->right, n - 1, ans);
        nthLevel2(root->left, n - 1, ans);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;

        int h = height(root);

        for (int level = 1; level <= h; level++) {

            vector<int> ans;

            if (level % 2 == 1)
                nthLevel(root, level, ans);
            else
                nthLevel2(root, level, ans);

            result.push_back(ans);
        }

        return result;
    }
};