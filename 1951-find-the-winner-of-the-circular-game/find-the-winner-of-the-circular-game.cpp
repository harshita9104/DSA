class Solution {
public:
    int findTheWinner(int n , int k) {
        vector<int> arr;
        for(int i =1; i<= n; i++){
            arr.push_back(i);
        }

        int i =0;//i vo index hai jha se start krna h count
        //or idx vo index jisko delete krna hai
        //delete krne k baad baaki elem ek index shift honge
        //to ab next iteration ka count jis elem se shuru hoga vo usi index par hoga 
        //jispar prev iteration ka last elem that jisko delete kiya
        while(arr.size() > 1){
            //if we are pointing at out of bound so to avoid it we should wrap around arr by taking modulo
            //0 based indexing so last elem will be at i+k-1
            int idx = (i+k-1)%arr.size();
            arr.erase(arr.begin() +idx);
            i = idx;//since the start of next count should be the last elem pos only after erase
        }

return arr[0];
    }
};