class Solution {
public:
    int searchHelper(vector<int>& nums, int low_idx, int high_idx, int target){
        if (low_idx > high_idx) return -1;

        int mid_point_idx = low_idx + (high_idx - low_idx)/2;


        if (target == nums[mid_point_idx])
            return mid_point_idx;
        else if (target < nums[mid_point_idx]) 
            return searchHelper(nums, low_idx, mid_point_idx -1, target);
        else if (target > nums[mid_point_idx])
            return searchHelper(nums, mid_point_idx +1, high_idx, target);

        return -1;
    }

    int search(vector<int>& nums, int target) {

        /*

        Binary Search

        Use the array and a low and a high index
        control direction of search using mid point
        update low and high using the mid point criteria
        and check if value is the mid point
        else return -1
        // how to handle 2 elements case
        */

        if (nums.size() == 0) return -1;

        int low_idx = 0;
        int high_idx = nums.size() -1;
        return searchHelper(nums, 0, high_idx, target);
        
    }
    
};

// #include <memory>
// #include <vector>
// #include <iostream>

// struct TreeNode {
//     int val;
//     std::unique_ptr<TreeNode> left;
//     std::unique_ptr<TreeNode> right;

//     TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
//     TreeNode(int n, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right) :
//     val(n), left(std::move(left)), right(std::move(right)) {}
// };

// class BST {
//     public:
//     std::unique_ptr<TreeNode> root;
// };

// void insert(std::unique_ptr<TreeNode>& node, int val) {
//     // if (!node) node->val = val; // make the node instead of trying to set val on a nullptr - which is undefined bahavior
//     if(!node){
//         node = std::make_unique<TreeNode>(val);
//         return;
//     }
//     // traverse and update
//     if (val < node->val) insert(node->left, val); // what if the value is pullptr?
//     else if (val > node->val) insert(node->right, val);

//     // skip repeitions
// }

// // inorder traversal to return a sorted list
// // only traversal, no creation or modification - hence borrow the ptr would be sufficient
// void sortedList(TreeNode* root, std::vector<int>& output){
//     if(!root) return;
//     sortedList(root->left.get(), output);
//     output.push_back(root->val);
//     sortedList(root->right.get(), output);
// }

// template<typename T>
// void printVector(std::vector<T>& data){
//     for (const auto val: data){
//         std::cout << val << " ";
//     }
//     std::cout << std::endl;
// }

// int main() {
//     std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};

//     BST _bst;
//     for (const auto val : data){
//         insert(_bst.root, val);
//     }

//     // init with default values;
//     std::vector<int> sorted_list;

//     sortedList(_bst.root.get(), sorted_list);

//     printVector(sorted_list);
// }


// #include <memory>
// #include <vector>
// #include <iostream>
// #include <cmath>
// #include <sstream>

// struct TreeNode {
//     int val;
//     std::unique_ptr<TreeNode> left;
//     std::unique_ptr<TreeNode> right;

//     TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
//     TreeNode(int n, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right) :
//     val(n), left(std::move(left)), right(std::move(right)) {}

//     void printNode(){
//         std::stringstream ss;
//         ss <<"  " << val << "  "<< std::endl;
//         if (left.get() && right.get()){
//             ss <<" /" << " " << "\ " << std::endl; 
//             ss <<left.get()->val << " " << right.get()->val << std::endl; 
//         } else if (left.get() && !right.get()){
//             ss <<" /" << std::endl; 
//             ss <<left.get()->val << std::endl; 
//         } else if (!left.get() && right.get()){
//             ss <<"  " << " " << "\ " << std::endl; 
//             ss <<"  " << " " << right.get()->val << std::endl; 
//         } // else no left or right

//         std::cout << ss.str() << std::endl;
//     }
// };

// class BST {
//     public:
//     std::unique_ptr<TreeNode> root;
// };

// void insert(std::unique_ptr<TreeNode>& node, int val) {
//     // if (!node) node->val = val; // make the node instead of trying to set val on a nullptr - which is undefined bahavior
//     if(!node){
//         node = std::make_unique<TreeNode>(val);
//         return;
//     }
//     // traverse and update
//     if (val < node->val) insert(node->left, val); // what if the value is pullptr?
//     else if (val > node->val) insert(node->right, val);

//     // skip repeitions
// }

// // inorder traversal to return a sorted list
// // only traversal, no creation or modification - hence borrow the ptr would be sufficient
// // passing unique_ptr ref even as const 
// void sortedList(TreeNode* root, std::vector<int>& output){
//     if(!root) return;
//     sortedList(root->left.get(), output);
//     output.push_back(root->val);
//     sortedList(root->right.get(), output);
// }

// template<typename T>
// void printVector(std::vector<T>& data){
//     for (const auto val: data){
//         std::cout << val << " ";
//     }
//     std::cout << std::endl;
// }

// // given a vector of say three point
// // add mid point 
// // get left arm of the curren mid point
// // and repeat
// // do the same for the right arm as well

// void makeBalancedTreeHelper(std::unique_ptr<TreeNode>& root, const std::vector<int>& sorted_data, int start, int end){
//     // if (start > sorted_data.size()/2.0) return;
//     // if (end < sorted_data.size()/2.0) return; // end would less than true mid point on the first iteration itself

//     // in recursion the iteration ends when the points corss pover
//     if (start > end) return; 


//     // get mid point
//     int mid_pt_idx = start + (end-start)/2.0;

//     insert(root, sorted_data[mid_pt_idx]);

//     // left arm (explicit move past the current mid pt - so that we can handle only 2 pts cases)
//     makeBalancedTreeHelper(root->left, sorted_data, start, mid_pt_idx-1); // how to handle index out of range - we actually take advantage of this for ending the recursion
//     makeBalancedTreeHelper(root->right, sorted_data, mid_pt_idx+1, end);

// }

// // can this be done in place?
// void makeBalancedTree(std::unique_ptr<TreeNode>& root){
//     /*
//     Algo:
//     1. get sorted data
//     2. get mid point of data [key is to identify root]
//     3. reset root
//     4. insert [mid_point_idx, 0]
//     5. insert [mid_point_idx, N]
//     */
//     std::vector<int> sorted_data;
//     sortedList(root.get(), sorted_data);
    
//     if (sorted_data.size() <= 0) return;


//     // clear the data, children included - thanks to the unique ptrs
//     root.reset();

//     // this version just makes a new root but does not balance the tree
//     // // left half of mid point
//     // for (int i = mid_pt_idx; i >=0; i--) {
//     //     insert(root, sorted_data[i]);
//     // }

//     // // right half od mid point
//     // for (int i = mid_pt_idx; i <sorted_data.size(); i++) {
//     //     insert(root, sorted_data[i]); // no need to worry about repetitions
//     // }

//     makeBalancedTreeHelper(root, sorted_data, 0, sorted_data.size()-1);
// }

// int height(TreeNode* root) {
//     if(!root) return 0;
//     int left_ht = height(root->left.get());
//     int right_ht = height(root->right.get());
//     return 1 + std::max(left_ht, right_ht);
// }

// void printTree(TreeNode* root){
//     if(!root) return;
//     // in order traversal
//     printTree(root->left.get());

//     root->printNode();

//     printTree(root->right.get());
// }

// int main() {
//     std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};

//     BST _bst;
//     for (const auto val : data){
//         insert(_bst.root, val);
//     }

//     std::cout << "Tree Ht: " << height(_bst.root.get()) << std::endl;

//     // init with default values;
//     std::vector<int> sorted_list;

//     sortedList(_bst.root.get(), sorted_list);

//     printVector(sorted_list);

//     makeBalancedTree(_bst.root);

//     std::cout << "Tree Ht: " << height(_bst.root.get()) << std::endl;

//     printTree(_bst.root.get());
// }

// #include <memory>
// #include <vector>
// #include <iostream>
// #include <cmath>
// #include <sstream>

// struct TreeNode {
//     int val;
//     std::unique_ptr<TreeNode> left;
//     std::unique_ptr<TreeNode> right;

//     TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
//     TreeNode(int n, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right) :
//     val(n), left(std::move(left)), right(std::move(right)) {}

//     void printNode(){
//         std::stringstream ss;
//         ss <<"  " << val << "  "<< std::endl;
//         if (left.get() && right.get()){
//             ss <<" /" << " " << "\\ " << std::endl; 
//             ss <<left.get()->val << " " << right.get()->val << std::endl; 
//         } else if (left.get() && !right.get()){
//             ss <<" /" << std::endl; 
//             ss <<left.get()->val << std::endl; 
//         } else if (!left.get() && right.get()){
//             ss <<"  " << " " << "\\ " << std::endl; 
//             ss <<"  " << " " << right.get()->val << std::endl; 
//         } // else no left or right

//         std::cout << ss.str() << std::endl;
//     }
// };

// bool searchForVal(TreeNode* root, int val){
//     // if val is less than root, check left 
//     // if val is more than root, check right
//     // once children are explored then check for parent
//     if(!root) return false;
//     if (val == root->val) return true; // pre/ post/in order?

//     bool found = false;
//     if (val < root->val) {
//         found = searchForVal(root->left.get(), val);
//     } else {
//         found = searchForVal(root->right.get(), val);
//     }
//     return found;
// }

// bool isValidBST(TreeNode* root, int low = -100, int high = 100){
//     if(!root) return false;
//     if (root->val > low && root->val < high) return true;
//     isValidBST(root->left.get(), low, root->val);
//     isValidBST(root->right.get(), root->val, high);
// }

// int checkBalance(TreeNode* root){
//     // returns height if balanced else -1
//     if(!root) return 0;
//     int left_ht = checkBalance(root->left.get());
//     if (left_ht == -1) return -1; // early exit
//     int right_ht = checkBalance(root->right.get());
//     if (right_ht == -1) return -1;
//     if (std::abs(left_ht - right_ht) > 1) return -1;

//     return 1 + std::max(left_ht, right_ht);
// }

// bool isBalanced(TreeNode* root){
//     return checkBalance(root) != -1;
// }

// class BST {
//     public:
//     std::unique_ptr<TreeNode> root;
// };

// void insert(std::unique_ptr<TreeNode>& node, int val) {
//     // if (!node) node->val = val; // make the node instead of trying to set val on a nullptr - which is undefined bahavior
//     if(!node){
//         node = std::make_unique<TreeNode>(val);
//         return;
//     }
//     // traverse and update
//     if (val < node->val) insert(node->left, val); // what if the value is pullptr?
//     else if (val > node->val) insert(node->right, val);

//     // skip repeitions
// }

// // inorder traversal to return a sorted list
// // only traversal, no creation or modification - hence borrow the ptr would be sufficient
// // passing unique_ptr ref even as const 
// void sortedList(TreeNode* root, std::vector<int>& output){
//     if(!root) return;
//     sortedList(root->left.get(), output);
//     output.push_back(root->val);
//     sortedList(root->right.get(), output);
// }

// template<typename T>
// void printVector(std::vector<T>& data){
//     for (const auto val: data){
//         std::cout << val << " ";
//     }
//     std::cout << std::endl;
// }

// // given a vector of say three point
// // add mid point 
// // get left arm of the curren mid point
// // and repeat
// // do the same for the right arm as well

// void makeBalancedTreeHelper(std::unique_ptr<TreeNode>& root, const std::vector<int>& sorted_data, int start, int end){
//     // if (start > sorted_data.size()/2.0) return;
//     // if (end < sorted_data.size()/2.0) return; // end would less than true mid point on the first iteration itself

//     // in recursion the iteration ends when the points corss pover
//     if (start > end) return; 


//     // get mid point
//     int mid_pt_idx = start + (end-start)/2.0;

//     insert(root, sorted_data[mid_pt_idx]);

//     // left arm (explicit move past the current mid pt - so that we can handle only 2 pts cases)
//     makeBalancedTreeHelper(root->left, sorted_data, start, mid_pt_idx-1); // how to handle index out of range - we actually take advantage of this for ending the recursion
//     makeBalancedTreeHelper(root->right, sorted_data, mid_pt_idx+1, end);

// }

// // can this be done in place?
// void makeBalancedTree(std::unique_ptr<TreeNode>& root){
//     /*
//     Algo:
//     1. get sorted data
//     2. get mid point of data [key is to identify root]
//     3. reset root
//     4. insert [mid_point_idx, 0]
//     5. insert [mid_point_idx, N]
//     */
//     std::vector<int> sorted_data;
//     sortedList(root.get(), sorted_data);
    
//     if (sorted_data.size() <= 0) return;


//     // clear the data, children included - thanks to the unique ptrs
//     root.reset();

//     // this version just makes a new root but does not balance the tree
//     // // left half of mid point
//     // for (int i = mid_pt_idx; i >=0; i--) {
//     //     insert(root, sorted_data[i]);
//     // }

//     // // right half od mid point
//     // for (int i = mid_pt_idx; i <sorted_data.size(); i++) {
//     //     insert(root, sorted_data[i]); // no need to worry about repetitions
//     // }

//     makeBalancedTreeHelper(root, sorted_data, 0, sorted_data.size()-1);
// }

// int height(TreeNode* root) {
//     if(!root) return 0;
//     int left_ht = height(root->left.get());
//     int right_ht = height(root->right.get());
//     return 1 + std::max(left_ht, right_ht);
// }

// void printTree(TreeNode* root){
//     if(!root) return;
//     // in order traversal
//     printTree(root->left.get());

//     root->printNode();

//     printTree(root->right.get());
// }

// int main() {
//     std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};

//     BST _bst;
//     for (const auto val : data){
//         insert(_bst.root, val);
//     }

//     std::cout << "Tree Ht: " << height(_bst.root.get()) << std::endl;

//     std::cout << "Is Balanced: " << isBalanced(_bst.root.get()) << std::endl;

//     // init with default values;
//     std::vector<int> sorted_list;

//     sortedList(_bst.root.get(), sorted_list);

//     printVector(sorted_list);

//     makeBalancedTree(_bst.root);

//     std::cout << "Tree Ht: " << height(_bst.root.get()) << std::endl;

//     // printTree(_bst.root.get());

//     std::cout << "is valid BST: " << isValidBST(_bst.root.get()) << std::endl;

//     std::cout << "Is Balanced: " << isBalanced(_bst.root.get()) << std::endl;

//     std::cout << "Search 1: " << searchForVal(_bst.root.get(), 1) << std::endl;
//     std::cout << "Search 10: " << searchForVal(_bst.root.get(), 10) << std::endl;
//     std::cout << "Search -1: " << searchForVal(_bst.root.get(), -1) << std::endl;
//     std::cout << "Search 5: " << searchForVal(_bst.root.get(), 5) << std::endl;
// }   


