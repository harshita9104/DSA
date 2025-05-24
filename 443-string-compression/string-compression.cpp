class Solution {
public:
    int compress(vector<char>& chars) {
        int i =0;
        int ansindex=0;
        int count =0;
        int n = chars.size();
        while(i<n){
            int j = i+1;//j will itertae and check the similar char count where i will stand on the first occ of unique char
            chars[ansindex] = chars[i];
            while(j<n && chars[i] == chars[j]){
                
                j++;
            }
            int count = j-i;//this will give the count for each char as j will be on the new unique char and i will be on the 1st char of prev char 
            ansindex++;
            if(count>1){
                string num = to_string(count);//imp if the count is more than 1 char
                for(char ch : num){
                    //iterate over this string which has count and enter each digit one by one
                    chars[ansindex] = ch;
                    ansindex++;
                }

            }
            //since j would be pointing to new unique char make i also point there
            i = j;

        }
        return  ansindex;

    }
};