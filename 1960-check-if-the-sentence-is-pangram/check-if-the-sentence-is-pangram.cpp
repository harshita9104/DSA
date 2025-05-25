class Solution {
public:
    bool checkIfPangram(string sentence) {
        // int arr[26] = {0};  // Track if each letter 'a' to 'z' is seen

        // for (auto ch : sentence) {
        //     arr[ch - 'a'] = 1;  // Mark the letter as seen
        // }

        // for (int i = 0; i < 26; i++) {
        //     if (arr[i] == 0) {
        //         return false;  // If any letter is missing, it's not a pangram
        //     }
        // }

        // return true;  // All letters found
       
       


        //since we just need to check if the sentence contain all 26 char of alphabet or not so we use a set of char and since set stores only unique elem we will insert all elem of sentence in it and check in the end if the size of set is 26 or not
        set<char> unique;
        for(auto ch: sentence){
            unique.insert(ch);
        }
        if(unique.size() == 26){
            return true;
        }else{
            return false;
        }
    }
};
