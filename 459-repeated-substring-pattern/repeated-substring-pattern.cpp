class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
//in this question two observation
//the length of sub string should divide the length of s then only if substr is appended certain no of imes it becomes eq to s
//no of times substr shd be repeated to be eq to s = n/i; where n %i == 0
//
        for(int i =1; i<= n-1; i++){//since min length of substr can be 1 start from 1 and i cannot keep the length of substr eq to string thats why it ended on n-1
            if(n % i ==0){//agar i length ki substr completely divides n
               int times = n/i;//to phir if this substr is appended this much no of times it will be eq to s 
               string sub = s.substr(0,i);
                string original_sub = sub; // Store the original substring
                
                while(times != 1){ // since substr is already being taken once before entering this loop so end this loop when 1 no of time is left
                    sub += original_sub; // Add the original substring, not the growing sub
                    times--;
                }
               if(sub == s){
                return true;
               }

            }
        }
    return false;
    }
};