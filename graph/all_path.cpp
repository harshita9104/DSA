class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         vector<vector<int>> paths;// Initialize an empty vector to store all paths
        vector<int> currentPath;// Initialize an empty vector to store the current path during exploration
        dfs(graph, paths, currentPath, 0);// Start DFS from source node (index 0)
        return paths;// Return the vector containing all found paths
        
    }
    private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& currentPath, int node) {
        currentPath.push_back(node);// Add the current node to the path

        if (node == graph.size() - 1) {// Check if we reached the target node
            paths.push_back(currentPath);// If yes, add the complete path to the results
        } else {
            for (int neighbor : graph[node]) { // Explore all neighbors of the current node
                dfs(graph, paths, currentPath, neighbor);// Recursive call for each neighbor
            }
        }
        currentPath.pop_back(); // Backtrack: Remove the current node from the path
    }
};
// Approach
// The class has two member functions:

// allPathsSourceTarget: This public function is the main entry point for finding all paths. It takes the graph as input (represented as a 2D vector of neighbor lists) and returns a vector of vectors, where each inner vector represents a path from source to target.
// dfs: This private function is a helper function that performs the Depth-First Search (DFS) traversal to explore all possible paths.
// allPathsSourceTarget:
// This function takes the graph (graph) as input.
// It creates two empty vectors:
// paths: This vector will eventually store all the found paths from source to target.
// currentPath: This vector will be used to keep track of the current path being explored during DFS.
// The function calls the helper function dfs with the following arguments:
// graph: The graph to explore.
// paths: The vector to store the found paths (passed by reference to modify it within the function).
// currentPath: The current path being explored (passed by reference to modify it within the function).
// 0: The starting node (index 0 is assumed to be the source node).
// Finally, the function returns the paths vector, which will contain all the discovered paths after the DFS exploration.
// dfs:
// This function performs the DFS traversal to find all paths.
// It takes the following arguments:
// graph: The graph to explore.
// paths: The vector to store the found paths (passed by reference).
// currentPath: The current path being explored (passed by reference).
// node: The current node being processed in the DFS traversal.
// The function performs the following steps:
// Adds the current node (node) to the currentPath vector.
// Checks if the current node is the target node (last node in the graph):
// If yes (node == graph.size() - 1), it means we've reached the end of a path. Therefore, the function copies the complete currentPath vector (representing a path from source to target) into the paths vector.
// If the current node is not the target:
// It iterates through all neighbors (neighbor) of the current node listed in graph[node].
// For each neighbor, it makes a recursive call to dfs with the following arguments:
// - The same graph.
// - The same paths vector (to add new paths found during exploration).
// - An updated currentPath vector that now includes the neighbor as the next node in the path.
// - The neighbor's index (neighbor) to explore that neighbor in the next DFS step.
// Complexity
// Time complexity: O(V * E), where:
// V is the number of vertices (nodes) in the graph.
// E is the number of edges (connections between nodes) in the graph.
// Space complexity:O(V), where:
// V is the number of vertices in the graph.