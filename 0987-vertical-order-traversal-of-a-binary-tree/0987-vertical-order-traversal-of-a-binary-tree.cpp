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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;
        dfs(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> res;
        int prevCol = INT_MIN;

        for (auto [col, row, val] : nodes) {
            if (col != prevCol) {
                res.push_back({});
                prevCol = col;
            }
            res.back().push_back(val);
        }

        return res;
    }

    void dfs(TreeNode* node, int row, int col, vector<tuple<int, int, int>>& nodes) {
        if (!node) return;
        nodes.emplace_back(col, row, node->val);
        dfs(node->left, row + 1, col - 1, nodes);
        dfs(node->right, row + 1, col + 1, nodes);
    }
};