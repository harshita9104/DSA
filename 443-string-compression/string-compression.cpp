class Solution {
public:
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
};