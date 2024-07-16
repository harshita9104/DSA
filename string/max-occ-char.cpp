#include <iostream>
#include <string>
using namespace std;

// Function to find the maximum occurring character in a string.
char getMaxOccuringChar(string str) {
    int arr[26] = {0}; // Array to store frequency of each character

    // Iterate over the string and count the frequency of each character
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) { // Ensure the character is a letter
            int pos = tolower(str[i]) - 'a'; // Convert character to lowercase and find position
            arr[pos]++;
        }
    }

    // Find the character with the maximum frequency
    int maxFreq = arr[0];
    int maxPos = 0;
    for (int j = 1; j < 26; j++) { // Start loop from 1 since arr[0] is already considered
        if (arr[j] > maxFreq) {
            maxFreq = arr[j];
            maxPos = j;
        }
    }
//return 'a' + maxPos;: This converts the index of the maximum frequency back to the corresponding character.

    // Return the character with the maximum frequency
    return 'a' + maxPos;
}

int main() {
    string str = "sample string";
    cout << "Maximum occurring character: " << getMaxOccuringChar(str) << endl;
    return 0;
}
