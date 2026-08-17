enum class : unsigned in {
    UNVISITED : 0,
    INPROGRESS: 1,
    DONE: 3;
} COURSE_STATUS;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        Directed Graph
        DSU 

        report is fullyConnected
        */

        unordered_map<int, vector<int>> adj;
        for (const auto& edge: prerequisites){
            adj[edge[0]].push_back(edge[1]);
        }

        std::unordered_map<int, int> state;

        for (int course = 0; course < numCourses; course ++) {
            state[course] = COURSE_STATUS::UNVISITED;
        }

        for (int course = 0; course < numCourses; course ++) {
            if (state[course] == COURSE_STATUS::UNVISITED  &&
                hasCycle(course, adj, state)) return false;
        }

        return true;
    }

    bool hasCycle(int course, const unordered_map<int, vector<int>>& adj, std::unordered_map<int, int>& state) {
        state[course] = COURSE_STATUS::INPROGRESS;

        for (const auto& dep: adj[course]){
            if (state[dep] == COURSE_STATUS::INPROGRESS) return true; //dep cannot be in progress 
            if(state[dep] == COURSE_STATUS::UNVISITED && hasCycle(course, adj, state)) return true;
        }
        state[course] = COURSE_STATUS::DONE;

        return false;
    }
};
