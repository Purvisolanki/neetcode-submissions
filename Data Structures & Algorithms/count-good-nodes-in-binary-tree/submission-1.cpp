class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count = 0;

        if (!root)
            return count;

        countGoodNode(root, count, root->val);

        return count;
    }

    void countGoodNode(TreeNode* root, int& count, int maxforthisstep) {

        if (root == NULL)
            return;

        if (root->val >= maxforthisstep) {
            count++;
            maxforthisstep = root->val;
        }

        countGoodNode(root->left, count, maxforthisstep);
        countGoodNode(root->right, count, maxforthisstep);
    }
};