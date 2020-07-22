/**
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

*/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        vector<int> one_result;
        if(!root) {
            return {};
        }
        TreeNode* itr;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        int level = 0;
        while (!nodes.empty()) {
            one_result.clear();
            queue<TreeNode*> level_nodes;
            while (!nodes.empty()) {
                itr = nodes.front();
                nodes.pop();
                one_result.push_back(itr->val);
                if (itr->left) {
                    level_nodes.push(itr->left);
                }
                if (itr->right) {
                    level_nodes.push(itr->right);
                }
            }
            nodes = level_nodes;
            if (level % 2) {
                reverse(one_result.begin(), one_result.end());
            }
            level += 1;
            result.push_back(one_result);
        }
        return result;
    }
};
