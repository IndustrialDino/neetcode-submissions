/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    std::unordered_map<int, Node*> explored_nodes_;

    Node* cloneGraph(Node* node) {
        /*
        Given a node (with no chilren) return a code of the node
        itself - using new operator

        // get all children before create the node (post-order)

        // seems like it's an undirected graph where every node has information about every 
        // other node it's connected to

        // hence we are running into a infinite loops

        Skip recursing on a node that has already been visited (From the input)
        Use the value as a way to track the nodes that have been explored
        */

        Node* clone = nullptr;
        if(!node) return clone;

        // create the Node itseld
        clone = new Node(node->val);
        explored_nodes_.insert({node->val, clone});

        std::vector<Node*> cloned_children;
        
        // now do that for every child in the node
        for (const auto& child: node->neighbors){
            // only recurse on nodes that have not been explored
            // using recursion only to explore
            if(!explored_nodes_.count(child->val))
                cloned_children.push_back(cloneGraph(child));
            else 
                cloned_children.push_back(explored_nodes_.at(child->val)); // ensure we still track the adjacencies (but push the newly created node and not the original node)
        }
        
        // complete the Node - still post order
        clone->neighbors = cloned_children;

        return clone;
    }
};
