class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        //ek index par khade hoke vo kitna max jump kr skta vo nikal lo phir us windows m jo maxjump ho skta hai vo hmare next window ka right index hoga 
        // or next window ka left index will be curr window ka right+1//kyuki is window m kitna duur ja skte the utna chle gye //ab iske baad wali window ko consider krna h before  considering next window jump++ karna or next iteration se phle windowfarthest ko 0 krdena

        int left = 0, right =0, jumps=0;
        while(right<n-1){
            //next window shuru krne se phle us window ki maxreach ko 0 krdo 
            int windowfarthest =0;
            //ab current window m iterate krke nikal lo kitna duur ja skte
            for(int i = left ; i<= right; i++){
                windowfarthest = max(windowfarthest, i+nums[i]);
            }
            left = right+1;//jha last window khtm hui uske baad next window shuru
            right = windowfarthest;//kyuki last window m khade rhke ek jump krke max is index tak aa skte h to ye hmari next window ka end hoga
            jumps++; 
        }
return jumps;

    }

};