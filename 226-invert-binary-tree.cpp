/*

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:

    Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.


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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        TreeNode* temp = root->left; 
        root->left = root->right; 
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

/*
Notes for future readers.

The logic is self evident, need to do so for each of the child. 
Could use a stack, but more intuitive is the recursion here.
Simply, get every guy to switch it's children.
Then repeat the same for the children. 
Then return the guy you start with, all wiggly inside now this laddie.
Ofcourse, the stop condition! The stop when something's NULL, you know.
*/
