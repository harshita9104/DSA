 //Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.
// For example, the string "aaaabbbccdaa" would be encoded as "a4b3c2d1a2".
// You must write an algorithm that uses only constant extra space.


 int compress(vector<char>& chars) {
        int i = 0;
        //kyuki alg se space nhi leni h hm jo resulting char or count h vo ansIndex p daalte jaenge chars arr m hi
        int ansindex = 0;
        int n = chars.size();
        while(i<n){
            
            //kyuki hme ek char ko uske aage vale index elem se compare karna h agar same hai to j++ kardo or uske aage vale elem ko bhi check karo 
            int j = i+1;
            //j, arr k baahar point nhi karna chahiye or j++ tab tak karna h jab tak char[i] == chars[j] hai hm 
            while(j<n && chars[i] == chars[j]){
                j++;
            }
            //old cchar char arr k ansindex p daalo or ansindex ++ karo
            chars[ansindex++] = chars[i];
            //ye loop k bahar tak aayenge jab ya to poora loop traverse ho gya hoga ya phir ek bya elem arr occur hua h j ab us naye elem p hi point kar rha 
            //ab old char ka count ansindex p daalna h
            int count = j-i;
            //ab count ko char arr m tab hi daalna h agar vo >1 hai or count integer agar 2 ya 3 digit ho to phle usko single digit m convert karke phir ek-ek karke char arr m daalna
             
            if(count>1){
                //convert count integer to string
                string cnt = to_string(count);
                //now traverse thr each character of this string and put it in char arr one by one
                for(char ch: cnt){
                    chars[ansindex++] = ch;
                }

            }
            // ab new elem jo ki j p point kar rha h i ko vha leke jao taaki new char or uske count ko bhi char arr m daal aao

            i = j;


        }
        return ansindex;
        


    }