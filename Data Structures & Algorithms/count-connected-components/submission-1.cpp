class Solution {
public:
    std::unordered_set<int> explored_nodes_;

    std::unordered_map<int, std::vector<int>> edges_simplified_;

    void addOrUpdateNode(int node_a, int node_b) {
        if (!edges_simplified_.count(node_a))
            edges_simplified_.insert({node_a, std::vector<int>{node_b}});
        else 
            edges_simplified_.at(node_a).push_back(node_b);
    }

    void parseEdges(const vector<vector<int>>& edges){
        for (const auto& entry: edges){
            addOrUpdateNode(entry[0], entry[1]);
            // since it's undirected - we need to maintain two ways 
            addOrUpdateNode(entry[1], entry[0]);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        /*
        iterate over n nodes
        if node not explored
            add to explored
            get all neighbors (recursive) of a node 
            and increment counter when neighors terminate

            track the nodes explored

        any cycles ? - assuming none
        */
        parseEdges(edges);
        int connected_components = 0;
        for (int node = 0; node < n; node++){
            // check edges to make there's atleast one connection for the given node
            if (!explored_nodes_.count(node) && edges_simplified_.count(node)){
                exploreNeighbors(node);
                connected_components += 1;
            }
        }

        return connected_components;
    }

    void exploreNeighbors(const int node){
        // unexplored
        if(!explored_nodes_.count(node)){
            explored_nodes_.insert(node);
            if (edges_simplified_.count(node)){
                for (const auto& neighbor: edges_simplified_.at(node))
                    exploreNeighbors(neighbor);
            }
        }
    }
};
