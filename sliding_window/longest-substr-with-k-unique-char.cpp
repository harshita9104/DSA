// Given a string you need to print the size of the longest possible substring that has exactly k unique characters.
int longestKSubstr(string s, int k) {

        int n=s.length();
        int i=0;
        int j=0;
        int count=0;
        unordered_map<char,int> mp;
        mp.clear();
        int res=0;
        
        while(j<n){
           
           // If already present in the map count will not change, if it is equal to k then the result will change as the maximum window size increases by 1
           if(mp.find(s[j])!=mp.end()){
               mp[s[j]]++;
               if(count==k){
                   res=max(res,j-i+1);
               }
               j++;
               continue;
           }
           
           //If not present in the map then it is unique so the count will increase
           mp[s[j]]++;
           count++;
           
           //After increasing the count if it is equal to k then we update the result
           if(count==k){
               res=max(res,j-i+1);
               j++;
           }
           //If the count is lesser we need a larger window size so we increase from right
           else if(count<k){
               j++;
           }
           //If the window size is greater than k the we reduce the window size from left
           else if(count>k){
               while(count>k){
                   // reduce the frequency of the leftmost window character
                   mp[s[i]]--;
                   //if the frequency is 0 it does not exist in the window so we remove it from the map and reduce the unique element count
                   if(mp[s[i]]==0){
                       mp.erase(s[i]);
                       count--;
                   }
                   i++;
                   //if it hits the condition while removing unique elements then we update the result
                   if(count==k){
                        res=max(res,j-i+1);
                   }
               }
               j++;
           }
        }
        return res==0? -1: res;
    }
};
