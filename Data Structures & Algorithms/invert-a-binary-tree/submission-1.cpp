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

    void copyInverseInPlace(TreeNode* source){
        if(!source) return;

        std::swap(source->left, source->right);

        copyInverseInPlace(source->left);
        copyInverseInPlace(source->right);

        // at this point Node has it's children inverted 
        // we could perform the swap here - for post order

        // for Swap type operations, pre/post order does not matter
        // since every node needs exactly one operation - does not need to look at it's grand children
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

        // TreeNode* result = nullptr;
        // copyInverse(root, result);
        // return result;
        copyInverseInPlace(root);
        return root;
    }
};
