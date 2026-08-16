class DSU {
    public:
    std::unordered_map<int, int> parent;

    int find(int node){
        if (parent[node] == node) return node;

        return find(parent[node]);
    }

    bool unite(int a, int b){
        int root_a = find(a);
        int root_b = find(b);

        if (root_a == root_b) return false;

        parent[root_a] = root_b;

        return true;
    }

    bool isFullyConnected() {
        // root should be the same across all nodes
        if(parent.size() == 0) return true;
        int root = find(0);
        for (const auto& [node, _] : parent){
            int node_root = find(node);
            if (node_root != root) return false;
        }

        return true;
    }
};

class Solution {
public:

    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu;
        for (int i = 0; i < n; i++){
            dsu.parent[i] = i;
        }

        for (const auto& edge: edges){
            bool united = dsu.unite(edge[0], edge[1]); // fail for cycle

            if (!united) return false;
        }

        // return true; // to check visited nodes and full connectedness
        return dsu.isFullyConnected();
    }


};
