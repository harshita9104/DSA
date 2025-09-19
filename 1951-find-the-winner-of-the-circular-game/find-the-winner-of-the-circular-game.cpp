// class Solution {
// public:
//     int findTheWinner(int n , int k) {
//         vector<int> arr;
//         for(int i =1; i<= n; i++){
//             arr.push_back(i);
//         }

//         int i =0;//i vo index hai jha se start krna h count
//         //or idx vo index jisko delete krna hai
//         //delete krne k baad baaki elem ek index shift honge
//         //to ab next iteration ka count jis elem se shuru hoga vo usi index par hoga 
//         //jispar prev iteration ka last elem that jisko delete kiya
//         while(arr.size() > 1){
//             //if we are pointing at out of bound so to avoid it we should wrap around arr by taking modulo
//             //0 based indexing so last elem will be at i+k-1
//             int idx = (i+k-1)%arr.size();
//             arr.erase(arr.begin() +idx);
//             i = idx;//since the start of next count should be the last elem pos only after erase
//         }

// return arr[0];
//     }
// };
//using queue- count krenge elem ko or 1 to k-1 elem ko front se pop krke , back m push kr denge
//phir kth elem bachega q k front par usko sirf pop kr denge
// phir front se phirse count shuru krenge and same cheez repeat krenge jab tak q.size() ==1
class Solution {
public:
    int findTheWinner(int n , int k) {
     queue<int> q;
     for(int i =1; i<= n; i++){
        q.push(i);
     }
     while(q.size() > 1){
        for(int i =1; i<= k-1; i++){
            q.push(q.front());
            q.pop();
        }//ye loop k baad front wale k-1 elem back m push ho jaenge
        //phir front par kth elem bachega
        q.pop();//usko sirf pop karna h
        //and this process will continue again for the rem elem until there is only 1 elem left in que
     }
     return q.front();
    }
};