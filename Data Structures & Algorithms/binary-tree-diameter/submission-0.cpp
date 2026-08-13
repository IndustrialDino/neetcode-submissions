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
    int heightHelper(TreeNode* root, int& max_diameter){
        if(!root) return 0;
        int left_ht = heightHelper(root->left, max_diameter);
        int right_ht = heightHelper(root->right, max_diameter);

        int diameter = left_ht + right_ht;
        max_diameter = max(diameter, max_diameter);

        return 1 + max(left_ht, right_ht);
    }
    int diameterOfBinaryTree(TreeNode* root) {

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
        int max_diameter = 0;

        int tree_ht = heightHelper(root, max_diameter);
        
        return max_diameter;
    }
};
