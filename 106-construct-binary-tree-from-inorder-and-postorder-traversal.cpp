/**

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

**/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
private:
    TreeNode* helper(vector<int>& inorder,int i,int j,vector<int>& postorder,int ii,int jj)
    {
        // tree:     8 4 10 3 6 9 11
        // Inorder   [3 4 6] 8 [9 10 11]
        // postorder [3 6 4]   [9 11 10] 8
        if(i >= j || ii >= jj)
            return NULL;
        
        int mid = postorder[jj - 1];
        
        auto f = find(inorder.begin() + i,inorder.begin() + j,mid);
        
        int dis = f - inorder.begin() - i;
        
        TreeNode* root = new TreeNode(mid);
        root -> left = helper(inorder,i,i + dis,postorder,ii,ii + dis);
        root -> right = helper(inorder,i + dis + 1,j,postorder,ii + dis,jj - 1);
        
        return root;
        
    }
};
