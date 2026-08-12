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
    int maxDepth(TreeNode* root) {
        // at every level inspect the further we proceed

        if (!root) return 0; // if the nullptr Node 
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);

        return 1 + max(left_height, right_height); // 1 to take care of only root
        
    }
};
