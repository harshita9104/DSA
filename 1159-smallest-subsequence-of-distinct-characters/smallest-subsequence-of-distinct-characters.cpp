class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> lastIndex;
        for(int i = 0; i < s.size(); i++){
            lastIndex[s[i]] = i;
        }
        
        // Track which characters are already in result
        vector<bool> inResult(26, false);
        stack<char> result;
        
        for(int j = 0; j < s.size(); j++){
            char currentChar = s[j];
            
            // If character already in result, skip it
            if(inResult[currentChar - 'a'] == true){
                continue;
            }
            
            // Remove characters from stack if:
            // 1. Stack is not empty
            // 2. Top character is lexicographically larger than current
            // 3. Top character appears later in string (we can use it later)
            while(!result.empty() && 
                  result.top() > currentChar && 
                  lastIndex[result.top()] > j){
                
                char removedChar = result.top();
                result.pop();
                inResult[removedChar - 'a'] = false;
            }
            
            // Add current character to result
            result.push(currentChar);
            inResult[currentChar - 'a'] = true;
        }
        
        // Build final string (need to reverse since we used stack)
        string answer = "";
        while(!result.empty()){
            answer = result.top() + answer; // Add to front to reverse
            result.pop();
        }
        
        return answer;
    }
};