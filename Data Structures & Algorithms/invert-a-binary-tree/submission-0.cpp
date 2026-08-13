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
    void copyInverse(TreeNode* source, TreeNode*& dest){
        if (!source) {
            dest = nullptr;
            return;
        }
        // create the children  
        TreeNode* result_left = nullptr;
        TreeNode* result_right = nullptr;

        // process
        copyInverse(source->left, result_left);
        copyInverse(source->right, result_right);

        // post order inversion
        dest = new TreeNode(
                source->val,
                result_right,
                result_left);
    }

    TreeNode* invertTree(TreeNode* root) {
        /*
        Algorithm:
        - use the TreeNode's copy operator to invert left and right
        - we want to do this recursively
        - post order traversal

        root 
        left, right
        */

        TreeNode* result = nullptr;


        copyInverse(root, result);

        return result;
    }
};
