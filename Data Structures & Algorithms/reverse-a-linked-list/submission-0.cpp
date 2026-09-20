/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    // void reverse(ListNode* parent == nullptr, ListNode* child) {
    //     if (child.next == nullptr){
    //         child.next == parent;
    //     } else {
    //         reverse(child, child.next);
    //     }
    //     return;
    // }
    ListNode* reverseListv1(ListNode* head) {
        /*
        A(0, B)
        B(1, nullptr)
        on reverse
        B(1, A)
        A(0, nullptr)
        */

        ListNode* curr = head; // current node we are processing
        ListNode* prev = nullptr; // prev becomes the next node in the reverse order

        while(curr != nullptr){

            // save the next node information in a local variable
            ListNode* temp =  curr->next;
            
            // update the future next node with the previous information
            curr->next = prev; //reverse the pointer
            
            // move forward
            // update the previous to be the curret node
            prev = curr;
            curr = temp; // the child node
        }
        // at the end prev points to the new head

        return prev;
    }

    ListNode* reverseList(ListNode* head) {
        /*
        the ptr to the current value need to stay as is 
        we only need to update the direction of next, i.e we need to update
        the pointer value of next - and the new value has to be previous
        */

        // we will be iterating over the the current node using the it's current next

        ListNode* curr = head;
        ListNode* prev = nullptr; // prev->next is not used

        while (curr) { // curr can only be updated by way of curr->next

            // take the case of a integer swap [a, b]
            /*
            t = a
            a = b
            b = t // the final assignment has to be from the temporary variable
            */

            // second, capture the curr.next in a temporary var
            ListNode* temp = curr->next; // temp->next is not used

            // fourth - the direction change - happens by updating curr->next to prev
            curr->next = prev;

            // third, we need to progress the previous as well
            prev = curr;
            // first set curr to temp
            curr = temp;
        } // loop exits when curr = nullptr

        // when curr = nullptr, prev is holding the last known Node - this is the head of the Reversed Linked List

        return prev;

    }
};
