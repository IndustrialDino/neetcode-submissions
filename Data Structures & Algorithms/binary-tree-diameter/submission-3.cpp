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
    int max_diameter = 0;
    int heightHelper(TreeNode* root){
        if(!root) return 0;
        int left_ht = heightHelper(root->left);
        int right_ht = heightHelper(root->right);
        max_diameter = max(left_ht + right_ht, max_diameter);

        return 1 + max(left_ht, right_ht);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        if (!root) return 0;
        /*
        Taking the case of a simple Tree of height 2 with 
            root 
        {left, right}

        the diameter in this case is 2

        if we expand this to 
            root

        Algorithm:
        get left Ht
        get right Ht
        Ht: 1 + max (Left_Ht, Right_Ht) -> ht of a node
        Diameter: Left + Right
        (Ht, Diameter)
        Ht to calulate the Parent's Ht
        Diameter to calcultate max diameter
        (need to know the max upto that point)
        pass this as an argument

        max (Diameter) - I'm not very sure how to gather this information 
        - for a recusive system
        */
        int tree_ht = heightHelper(root);
        
        return max_diameter;
    }
};
