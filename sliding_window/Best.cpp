#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

// Union-Find data structure
class UnionFind {
public:
    // Initialize Union-Find structure with 'n' elements
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // Each element is its own parent initially
        }
    }

    // Find the root of element 'x' with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    // Union operation to connect elements 'x' and 'y'
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;  // Parent pointers
    vector<int> rank;    // Rank (height) of trees
};

// Function to get N similar movies with the highest rating
vector<string> getSimilarMovies(const string& movie, int N, 
                                const unordered_map<string, int>& ratings, 
                                const unordered_map<string, vector<string>>& similarMovies) {
    // Map movie titles to indices
    unordered_map<string, int> movieIndex;
    int index = 0;
    for (const auto& pair : ratings) {
        movieIndex[pair.first] = index++;
    }

    // Initialize Union-Find structure
    UnionFind uf(index);

    // Unite similar movies
    for (const auto& pair : similarMovies) {
        int movie1 = movieIndex[pair.first];
        for (const string& similarMovie : pair.second) {
            int movie2 = movieIndex[similarMovie];
            uf.unite(movie1, movie2);
        }
    }

    // Find all movies in the same connected component as the given movie
    int movieRoot = uf.find(movieIndex[movie]);
    vector<pair<int, string>> similar;
    for (const auto& pair : movieIndex) {
        if (uf.find(pair.second) == movieRoot) {
            similar.push_back({ratings.at(pair.first), pair.first});
        }
    }

    // Sort the similar movies by rating in descending order
    sort(similar.rbegin(), similar.rend());

    // Collect the top N movies
    vector<string> result;
    for (int i = 0; i < min(N, (int)similar.size()); ++i) {
        result.push_back(similar[i].second);
    }

    return result;
}

// Example usage
int main() {
    // Movie ratings
    unordered_map<string, int> ratings = {
        {"Movie A", 6},
        {"Movie B", 7},
        {"Movie C", 8},
        {"Movie D", 9}
    };

    // Similar movies relationship
    unordered_map<string, vector<string>> similarMovies = {
        {"Movie A", {"Movie B"}},
        {"Movie B", {"Movie A", "Movie C"}},
        {"Movie C", {"Movie B"}},
        {"Movie D", {}}
    };

    // Get recommendations
    vector<string> recommendations = getSimilarMovies("Movie A", 1, ratings, similarMovies);
    for (const string& movie : recommendations) {
        cout << movie << endl;  // Output: Movie C
    }

    return 0;
}
