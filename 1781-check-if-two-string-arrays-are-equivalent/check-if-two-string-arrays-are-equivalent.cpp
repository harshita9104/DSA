class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i =0;
        int j =0;
        //take 2 pointer to iterate over both vectors and take two string to store there concatenated results 
        string one;
        string two;
        //even if one vector iteration is complete we need to keep moving to fully concatenate the other vector values thats why use OR
        while(i< word1.size() || j< word2.size()){
            if(i<word1.size()){
               one += word1[i]; i++;
            }//if cond nhi lgayi to overflow hoga 
            if(j<word2.size()){
              two += word2[j]; j++;
            }
            
        }
        if(one == two){
            return true;
        }else{
            return false;
        }
    }
};