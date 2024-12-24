#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

// Function to get N similar movies with the highest rating
vector<string> getSimilarMovies(const string& movie, int N, 
                                const unordered_map<string, int>& ratings, 
                                const unordered_map<string, vector<string>>& similarMovies) {
    unordered_set<string> visited;  // To keep track of visited movies
    queue<string> q;  // Queue for BFS
    vector<vector<string>> buckets(11);  // Buckets for ratings from 0 to 10

    // Start BFS from the given movie
    q.push(movie);
    visited.insert(movie);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        for (const string& neighbor : similarMovies.at(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
                buckets[ratings.at(neighbor)].push_back(neighbor);
            }
        }
    }

    // Collect the top N movies from the buckets
    vector<string> result;
    for (int rating = 10; rating >= 0 && result.size() < N; --rating) {
        for (const string& movie : buckets[rating]) {
            if (result.size() < N) {
                result.push_back(movie);
            } else {
                break;
            }
        }
    }

    return result;
}

// Example usage
int main() {
    unordered_map<string, int> ratings = {
        {"Movie A", 6},
        {"Movie B", 7},
        {"Movie C", 8},
        {"Movie D", 9}
    };

    unordered_map<string, vector<string>> similarMovies = {
        {"Movie A", {"Movie B"}},
        {"Movie B", {"Movie A", "Movie C"}},
        {"Movie C", {"Movie B"}},
        {"Movie D", {}}
    };

    vector<string> recommendations = getSimilarMovies("Movie A", 1, ratings, similarMovies);
    for (const string& movie : recommendations) {
        cout << movie << endl;  // Output: Movie C
    }

    return 0;
}
