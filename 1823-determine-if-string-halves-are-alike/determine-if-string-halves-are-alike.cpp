class Solution {
public:
    bool halvesAreAlike(string s) {
        // set m count() method ye batata ki agar elem present hai set m to vo 1 return krta nhi to 0
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int vcount =0;
        int left =0;
        int n = s.size();
        int right = n-1;
        //use 2 pointer to check vowels for both the parts of string
        //acc to this cond left or right adj hoke ruk jaenge given string is even
        while(left<right){
            //to agar left pointer vala char vowel hua to count +1 
            if(vowels.count(s[left])) vcount++;
            //or right vala char vowel hua to count--
            if(vowels.count(s[right])) vcount--;
            left++;
            right--;
        }
        //agar dono parts m vowel eq hue to after complete iteration of string count will be 0 
        return vcount==0;
    }
};