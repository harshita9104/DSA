//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
//refer notes

int trap(vector<int>& height) {
        //observations
        //bar needs a valley to trap water i.e, larger bars on both sides
        //min of (left largest and right largest ) - height of bar give the final water trapped by a bar 
        int n = height.size();
        //utne size ki arr banao jitne max height arr ki size di h
        int leftmax[20000];
        int rightmax[20000];
        leftmax[0] = height[0];
        rightmax[n-1] = height[n-1];
        //har bar k liye uska leftmax bar height niklni h 
        for(int i = 1; i<n; i++){
            //leftmax[i-1] stores max among the height of its prev bars
            leftmax[i] = max(leftmax[i-1] , height[i-1]);
        }
        for(int i = n-2; i>=0; i--){
            rightmax[i] = max(rightmax[i+1] , height[i+1]);
        }
        int watertrapped = 0;
        for(int i =0; i<n; i++){
            int currwater = min(leftmax[i], rightmax[i]) - height[i];
            if(currwater>0){
                watertrapped += currwater;
            }
        }

      return watertrapped;  
    }