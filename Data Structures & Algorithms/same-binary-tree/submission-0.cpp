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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // tarverse - get in order data 
        // sudtract the "ordered" data (may not be sorted, if tree is not balanced or is invalid)
        // get sum (of abs difference) == 0 
        
        /*
        Algorithm:
        if both p and q are null return true
        if only one of p or q is null return false
        if p-val and q-val are different return false
        if p and q and p-val == qval
            return recurse (p-left, q-left) && recurse (p-right, q-right)
        
        return false
        */

        if (!p && !q) return true;
        // since we only 1 true state - we can check for that and default to false
        if ((p && q) &&(p->val == q->val))
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        return false;
    }
};
