class Solution {
public:
    void reverseString(vector<char>& s) {
        //2 pointers lo start or end m or unko swap karte hue move karo in the end puri string reverse ho jaegi
        int start = 0;
        int n = s.size();
        int end = n-1;
        while(start <= end){
          swap(s[start],s[end]);
          start++;
          end--;
        }
       

        
    }
};