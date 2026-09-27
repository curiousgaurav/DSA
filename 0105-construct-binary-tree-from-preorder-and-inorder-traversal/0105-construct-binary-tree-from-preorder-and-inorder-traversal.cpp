class Solution {
public:

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int ps, int pe, int is, int ie) {

        if (ps > pe || is > ie)
            return NULL;

        // First element of preorder = root
        int rootVal = preorder[ps];

        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder
        int index = is;

        while (inorder[index] != rootVal)
            index++;

        // Number of nodes in left subtree
        int leftSize = index - is;

        // Build left subtree
        root->left = build(preorder, inorder,
                           ps + 1,
                           ps + leftSize,
                           is,
                           index - 1);

        // Build right subtree
        root->right = build(preorder, inorder,
                            ps + leftSize + 1,
                            pe,
                            index + 1,
                            ie);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();

        return build(preorder, inorder,
                     0, n - 1,
                     0, n - 1);
    }
};