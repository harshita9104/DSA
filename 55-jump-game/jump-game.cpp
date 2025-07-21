class Solution {
public:
    bool canJump(vector<int>& nums) {
        //  maxindex i can reach standing at a point so traverse kro arr m ek index pr khade hoke us index + nums[index] ki val is maxindex i can reach and then index++ agar , har index par khade hoke maxindex calculate kro , agar maxindex> nums.size()-1, ho jae to true return krdo
        // agar maxindex curr maxindex se chota h to kuch mt kro
       //If you ever reach an index that you cannot reach (i > maxindex), you should stop because you're stuck.

 int maxReach = 0; // The farthest index we can reach so far
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                // We cannot reach this position; stuck
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) {
                // Can reach or jump past the last index
                return true;
            }
        }
        return true; // If loop finishes, we can reach the end
    }
};