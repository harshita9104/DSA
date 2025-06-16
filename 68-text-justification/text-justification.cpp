

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int total = words[index].size();
            int last = index + 1;

            // Find how many words fit in the current line
            while (last < n && total + words[last].size() + (last - index) <= maxWidth) {
                total += words[last].size();
                last++;
            }

            string line;
            int numWords = last - index;
            int numSpaces = maxWidth - total;

            // If it's the last line or only one word, left-justify
            if (last == n || numWords == 1) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' '); // Fill remaining spaces
            } else {
                // Fully justify the line
                int spacePerWord = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);

                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) { // Add spaces between words
                        line += string(spacePerWord + (i - index < extraSpaces ? 1 : 0), ' ');
                    }
                }
            }

            ans.push_back(line);
            index = last; // Move to the next group of words
        }

        return ans;
    }
};