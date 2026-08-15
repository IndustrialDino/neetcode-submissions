class Solution {
public:
    std::unordered_set<int> explored_nodes_;

    std::unordered_map<int, int> edges_simplified_;

    void parseEdges(const vector<vector<int>>& edges){
        for (const auto& entry: edges){
            edges_simplified_.insert({entry[0], entry[1]});
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
            if(edges_simplified_.count(node))
                exploreNeighbors(edges_simplified_.at(node));
        }
    }
};
