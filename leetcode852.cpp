//find peak index in a mountain array
class Solution {
public:
    int peakIndexInMountainArray(int* arr) {
        int start = 0; int end = arr.size() - 1;
        int mid = (start+end)/2;
        while(start< end){
             if(arr[mid]< arr[mid+1]){
                start = mid+1;
             }else{
                end = mid;
             }
             mid = (start+end)/2;

        }
        return start;
       
    }
};