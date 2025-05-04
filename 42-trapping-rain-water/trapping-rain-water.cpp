class Solution {
public:
    int trap(vector<int>& height) {
        //arr k har ek index k liye uska right max elem or left max elem nikalna hai usme se jo smaller hua (uski height - bar height )* width is eq to vol 
        int n = height.size();
        vector<int> left(n);
        left[0] = 0;
        vector<int> right(n);
        right[n-1] = 0;
        for(int i = 1; i<n ; i++){
            left[i] = max(left[i-1],height[i-1] );
        }
        for(int i = n-2; i>=0 ; i--){
            right[i] = max(right[i+1],height[i+1] );
        }
        int volume = 0;
    for (int i = 0; i < n; i++) {
        int trapheight = min(left[i], right[i]);
        int trapped = trapheight - height[i];
        if (trapped > 0)
            volume += trapped;
    }

    return volume;    
    }
};