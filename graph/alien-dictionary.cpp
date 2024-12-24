// ### Problem Understanding

// We need to determine the order of characters in an alien language based on the given list of words sorted according to this language. This is similar to finding the order of characters in the English alphabet but tailored to an unknown language.

// ### Approach

// 1. **Graph Representation**:
//    - Treat each character as a node in a graph.
//    - If a character appears before another character in the list of words, draw a directed edge from the first character to the second.

// 2. **Topological Sorting**:
//    - We use topological sorting to determine the order of nodes (characters) in a Directed Acyclic Graph (DAG).
//    - Topological sorting provides a linear order of nodes such that for any directed edge `u -> v`, `u` comes before `v`.

// ### Detailed Steps

// 1. **Build the Graph**:
//    - Initialize an adjacency list to represent the graph and an in-degree array to count incoming edges for each character.
//    - Compare each pair of adjacent words in the list:
//      - Find the first different character between the two words.
//      - Create a directed edge from the character in the first word to the character in the second word.
//      - Increment the in-degree of the destination character by 1.

// 2. **Topological Sort Using Kahn's Algorithm**:
//    - Initialize a queue to store characters with zero in-degree (no other characters come before them).
//    - For each character with zero in-degree, add it to the queue.
//    - Process characters from the queue:
//      - Add the character to the result string.
//      - Reduce the in-degree of all its neighbors by 1.
//      - If any neighbor's in-degree becomes zero, add it to the queue.
//    - Continue this process until all characters are processed.

// ### Complexity Analysis

// - **Time Complexity**: \(O(V + E)\)
//   - \(V\) is the number of characters (nodes) in the graph, which is `k`.
//   - \(E\) is the number of edges in the graph, which is the number of character comparisons we make between adjacent words.
//   - Building the graph involves comparing each pair of adjacent words and each character within those words. This takes \(O(V + E)\) time.
//   - The topological sort also takes \(O(V + E)\) time.

// - **Space Complexity**: \(O(V + E)\)
//   - Storing the graph (adjacency list) requires \(O(V + E)\) space.
//   - The in-degree array and the queue require \(O(V)\) space.

// ### Code Explanation

// ```cpp
class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        vector<int> indegree(k, 0); // Array to count in-degrees of characters
        vector<int> adj[k]; // Adjacency list to store graph edges
        
        // Build the graph
        for(int i = 0; i < n - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            
            for(int j = 0; j < len; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a'); // Create edge from s1[j] to s2[j]
                    indegree[s2[j] - 'a']++; // Increment in-degree of s2[j]
                    break;
                }
            }
        }
        
        // Queue to store characters with zero in-degree
        queue<int> q;
        for(int i = 0; i < k; i++) {
            if(indegree[i] == 0) q.push(i); // Add characters with zero in-degree to queue
        }
        
        // String to store the result
        string ans = "";
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans += (char)(node + 'a'); // Add character to result
            
            // Reduce in-degree of neighboring nodes
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it); // Add neighbors with zero in-degree to queue
            }
        }
        
        return ans;
    }
};


// ### Simple Explanation

// 1. **Build the Graph**:
//    - Compare each pair of adjacent words to find the first different character.
//    - Use this difference to create a directed edge from one character to another in the graph.
//    - Track how many edges point to each character (in-degree).

// 2. **Topological Sort**:
//    - Start with characters that have no incoming edges (in-degree of zero).
//    - Use a queue to process these characters, adding them to the result string.
//    - For each processed character, decrease the in-degree of its neighbors.
//    - If any neighbor's in-degree becomes zero, add it to the queue.
//    - Continue until all characters are processed.

// By following this approach, we determine the order of characters in the alien language. The use of a graph and topological sorting ensures we respect the order given by the input words.