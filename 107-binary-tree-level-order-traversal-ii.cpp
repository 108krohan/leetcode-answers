



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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<vector<int>> result;
        vector<int> one_result;
        TreeNode* temp = root;
        one_result.push_back(temp->val);
        queue<TreeNode*> q;
        q.push(temp);
        while(!q.empty()) {
            result.push_back(one_result);
            one_result.clear();
            queue<TreeNode*> new_queue;
            while(!q.empty()) {
                temp = q.front();
                if(temp->left) {
                    new_queue.push(temp->left);
                    one_result.push_back(temp->left->val);               
                }
                if(temp->right) {
                    new_queue.push(temp->right);
                    one_result.push_back(temp->right->val);
                }
                q.pop();
            }
            q = new_queue;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

