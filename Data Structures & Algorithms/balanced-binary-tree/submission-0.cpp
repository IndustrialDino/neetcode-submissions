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

    int verifyHeight(TreeNode* root){

        if (!root) return 0;
        int left_ht = verifyHeight(root->left);
        int right_ht = verifyHeight(root->right);
        if (abs(left_ht - right_ht) > 1) return -1;

        int ht = 1 + max(left_ht, right_ht);

        return ht;
    }

    bool isBalanced(TreeNode* root) {
        /*
        Algorithm:
        get left ht 
        get right ht
        if (|left_ht - right| >1) return -1;

        ht = 1 + max(left_ht, right_t)
        return ht 
        */
        int ht = verifyHeight(root);

        return ht != -1;
    }
};
