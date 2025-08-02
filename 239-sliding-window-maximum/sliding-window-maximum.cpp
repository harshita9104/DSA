class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // isme dikkat tab aayegi jab mai window slide kr rhi , or jo elem remove hone wala ho vahi curr max ho to ab mujhe rem elem ka max chahiye hoga , i cannot iterate over rem elem and find it bcoz, that isgiving tle 
        //so i need a data structure to store the useful elem and that data struc shd be open from both the ends so that i can access the max elem from front and remove smaller elem from back ,and when sliding if the curr max elem that is elem at front of list is that elem only which is going to be removed from the winodw then pop it from front,
        //  such data struc is either list or deque
        int i =0;
        int j =0;
         list<int> l;
        vector<int> ans;
        while(j<nums.size()){
           
            //but only the max shd remain at the front of deque so we will run a while loop and remove all the smaller elem from back of deque and will only push current j index elem after all the smaller elem before it are poped from deque
            while( l.back() < nums[j] && l.size()>0){
                l.pop_back();
            }
            l.push_back(nums[j]);
            if(j-i+1<k)j++;
            //smaller elm bhi push hue lekin jab unse bada elem dala usse phle phle wale smaller elem ko pop kr dia to ab dq k front par top elem h window size hit ho gya h
            else if(j-i+1 == k){
                ans.push_back(l.front());
                //ab i ko move krne se phle check krlo kahi deque k front pr nums[i] to nahi h na, agar h to ab hm window slide krenge to nums[i] current window m nahi rhega to usko deque se bhi hta do
                if(l.front() == nums[i])l.pop_front();
                i++;
                j++;

            }

        }
        return ans;

    }
};