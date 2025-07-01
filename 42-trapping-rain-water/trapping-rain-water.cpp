class Solution {
public:
    int trap(vector<int>& height) {
        // left or right max find krna hoga har ek index ka
        // inme se jo min hoga usme se subtract krna hoga current indes ki height
        // or agar result pos aaya to vol m add krdo width = 1 so simply add
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0;//0th index ka left m koi height nhi to max height is 0
        right[n-1] =0;//last index k right m koi nhi to right max height  =0

        for(int i =1; i<n; i++){
           //current index par jab hm hai to hmare pass prev index ka leftmax or prev index ki height h , ab curr index ka left max find krne k liye prev index ki height or prev index k leftmax m se jo max hai vo 
           left[i] = max(left[i-1], height[i-1]);

        }
        for(int i = n-2; i>=0; i--){
            right[i] = max(right[i+1], height[i+1]);
        }
int volume =0;
        for(int i =0; i<n; i++){
            int trappingHeight = min(left[i], right[i]);
            int trappedHeight = trappingHeight - height[i];
            if(trappedHeight >0)volume += trappedHeight;
        }
        return volume;
    }
};