class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while(i<n){
            if(arr[i] == 0){
                arr.insert(arr.begin() +i, 0);//insert a 0 at the ith index making other elem shift towards right 
                i = i+2; //skip the original 0 and the inserted 0 
            }else{
            i++;//simply move if its not 0
            }
            
        }
        //since its given in q tht Note that elements beyond the length of the original array are not written. so we resize the arr to n ignoring the elm beyond its actual size

       arr.resize(n);

    }
};