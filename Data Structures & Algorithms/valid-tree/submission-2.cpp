void printMap(const std::unordered_map<int>& data){
    for (const auto& val: data){
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /*
        Key: given a tree, during depth traversal, if a node's nieghbor is 
        one of the visited nodes - then we have a cycle

        Algorithm:
        - build an adjacency list given the edges
        - traverse the nodes - ideally from root (but we could start from anywhere) 
        - - and check for any cycles (other than itself, parent) (recursion). Return false if detected a cycle
        - ensure we have visited all nodes, else return false
        */

        if (edges.size() != n-1) return false;

        std::unordered_map<int ,vector<int>> adjacency_map;
        for (const auto& edge: edges){
            const int& node_a = edge[0];
            const int& node_b = edge[1];

            // undirected - 2 way
            adjacency_map[node_a].push_back(node_b);
            adjacency_map[node_b].push_back(node_a);

        }


        std::unordered_set<int> visited_nodes;
        for (int node = 0; node < n; node++){
            if (visited_nodes.count(node)) continue;

            visited_nodes.insert(node);
            const auto& neighbors = adjacency_map.at(node);
            for (const auto& neighbor: neighbors) {
                printMap(visited_nodes);
                if(hasCycles(neighbor, node, adjacency_map, visited_nodes)) return false;
            }
        }

        std::cout << "n: " << n << std::endl;
        std::cout << "visited nodes: " << visited_nodes.size() << std::endl;

        return visited_nodes.size() == n;
    }

    bool hasCycles(int node, int parent, const std::unordered_map<int ,vector<int>>& adjacency_map, std::unordered_set<int>& visited_nodes) {
        std::cout << "parent: " << parent << std::endl;
        std::cout << "node: " << node << std::endl;

        const auto& neighbors = adjacency_map.at(node);
        for (const auto& neighbor: neighbors){
            std::cout << "neighbor: " << neighbor << std::endl;
            if (neighbor == parent) continue; // skip checking for parennt
            printMap(visited_nodes);
            if (visited_nodes.count(neighbor)) return true; // if seen neighbor - then has cycle
            visited_nodes.insert(neighbor);
            if(hasCycles(neighbor, node, adjacency_map, visited_nodes)) return true; // check recursivelt and return true if has cycles
        }

        return false;
    }
};
