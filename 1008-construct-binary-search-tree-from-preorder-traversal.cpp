Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Note: 

    1 <= preorder.length <= 100
    The values of preorder are distinct.


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bstFromPreorderHelper(preorder,
                                     numeric_limits<int>::min(),
                                     numeric_limits<int>::max(),
                                     index);
    }
    
private:
    TreeNode* bstFromPreorderHelper(const vector<int>& preorder,
                                    int left,
                                    int right,
                                    int &index) {

        if (index == preorder.size() ||
            preorder[index] < left ||
            preorder[index] > right) {
            return nullptr;
        }
        
        auto root = new TreeNode(preorder[(index)++]);
        root->left = bstFromPreorderHelper(preorder, left, root->val, index);
        root->right = bstFromPreorderHelper(preorder, root->val, right, index);
        return root;
    }
    // Below solution doesn't work. Some help is here needed.
    // TreeNode* bstFromPreorder(vector<int>& preorder) {
    //     if(preorder.empty()) return NULL;
    //     TreeNode* root = new TreeNode(preorder.front());
    //     TreeNode* start = root;
    //     queue<TreeNode*> child_queue; 
    //     child_queue.push(root);
    //     int index = 1;
    //     // [8,5,1,7,10,12]
    //     // 1-index: 1 has children: 2 and 3
    //     //          2 has children: 4 and 5
    //     // 0-index: 0 has children: 1 and 2
    //     //          1 has children: 3 and 4
    //     while(index < preorder.size() / 2) {
    //         int left_child = preorder.at(index * 2 - 1); 
    //         int right_child = preorder.at(index * 2);
    //         TreeNode* temp = child_queue.front();
    //         child_queue.pop();
    //         TreeNode* left_node = new TreeNode(left_child);
    //         TreeNode* right_node = new TreeNode(right_child);
    //         temp->left = left_node;
    //         temp->right = right_node;
    //         child_queue.push(left_node); 
    //         child_queue.push(right_node);
    //         index += 1;
    //     }
    //     return start;
    // }
};
