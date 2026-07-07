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
    int maxPathSum(TreeNode* root) {
        int value = INT_MIN;
        height(root, value);
        return value;
    }
private:
    int height(TreeNode* node, int& value){
        if(!node) return 0;

        int left = max(0, height(node->left, value));
        int right = max(0, height(node->right, value));

        value = max(value, left + right + node->val);

        return node->val + max(left, right);
    }
};