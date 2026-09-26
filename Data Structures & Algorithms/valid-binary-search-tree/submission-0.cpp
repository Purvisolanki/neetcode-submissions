class Solution {
public:

    bool isValid(TreeNode* root, long long minVal, long long maxVal) {

        if (root == NULL)
            return true;

        // Current node must be inside the allowed range
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // Left: values must be smaller than root
        // Right: values must be greater than root
        return isValid(root->left, minVal, root->val) &&
               isValid(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};