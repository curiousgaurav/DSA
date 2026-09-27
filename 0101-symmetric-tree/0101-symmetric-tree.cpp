class Solution {
public:

    TreeNode* invert(TreeNode* root) {
        if (root == NULL)
            return NULL;

        swap(root->left, root->right);

        invert(root->left);
        invert(root->right);

        return root;
    }

    bool sameTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 == NULL || root2 == NULL)
            return false;

        if (root1->val != root2->val)
            return false;

        return sameTree(root1->left, root2->left) &&
               sameTree(root1->right, root2->right);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        root->left = invert(root->left);

        return sameTree(root->left, root->right);
    }
};