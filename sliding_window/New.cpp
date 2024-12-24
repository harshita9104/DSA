#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

// Define a structure to store movie ratings
struct Movie {
    int id;
    double rating;

    // Overload the less-than operator for sorting by rating
    bool operator<(const Movie& other) const {
        return rating > other.rating; // Sort in descending order by rating
    }
};

// Function to perform BFS and find all similar movies
vector<int> findSimilarMovies(int start, unordered_map<int, vector<int>>& similarityGraph) {
    vector<int> similarMovies;
    unordered_set<int> visited;
    queue<int> q;

    // Start BFS from the input movie
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int currentMovie = q.front();
        q.pop();
        similarMovies.push_back(currentMovie);

        // Explore all similar movies
        for (int neighbor : similarityGraph[currentMovie]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    return similarMovies;
}

// Function to return top N movies with the highest ratings using BFS and a min-heap
vector<int> recommendMovies(int start, int N, vector<double>& ratings, unordered_map<int, vector<int>>& similarityGraph) {
    // Get all similar movies using BFS
    vector<int> similarMovies = findSimilarMovies(start, similarityGraph);

    // Min-heap (priority queue) to keep track of the top N movies with highest ratings
    priority_queue<Movie, vector<Movie>> topMovies;

    // Traverse through the similar movies and maintain top N highest-rated movies
    for (int movie : similarMovies) {
        topMovies.push({movie, ratings[movie]});
        // Keep only top N movies in the heap
        if (topMovies.size() > N) {
            topMovies.pop(); // Remove the lowest-rated movie if we have more than N
        }
    }

    // Extract movies from the heap
    vector<int> result;
    while (!topMovies.empty()) {
        result.push_back(topMovies.top().id);
        topMovies.pop();
    }

    // Sort the result by rating in descending order
    sort(result.begin(), result.end(), [&](int a, int b) {
        return ratings[a] > ratings[b]; // Sort by ratings (descending)
    });

    return result;
}

int main() {
    // Movie ratings (as floating-point numbers): movieID -> rating
    vector<double> ratings = {6.5, 7.2, 8.3, 9.1}; // For movies A, B, C, D (0-based index)

    // Similarity graph where each movie is a node and edges represent similarity
    unordered_map<int, vector<int>> similarityGraph;
    similarityGraph[0] = {1}; // Movie A is similar to Movie B
    similarityGraph[1] = {0, 2}; // Movie B is similar to Movie A and Movie C
    similarityGraph[2] = {1}; // Movie C is similar to Movie B

    // Start movie is Movie A (index 0), and we want 2 recommendations
    int startMovie = 0;
    int N = 2;

    // Get movie recommendations
    vector<int> recommendations = recommendMovies(startMovie, N, ratings, similarityGraph);

    // Output recommended movies
    for (int movie : recommendations) {
        cout << "Recommended Movie: " << "Movie " << char(movie + 'A') << " with rating " << ratings[movie] << endl;
    }

    return 0;
}