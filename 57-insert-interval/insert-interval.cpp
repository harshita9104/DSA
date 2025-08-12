class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

       
        sort(intervals.begin(), intervals.end()); 

        for(auto it: intervals)
        {
            //if interval before is smaller add that
            if(it[1] < newInterval[0]) 
                ans.push_back(it);

            //if the newInterval is smaller add that
            else if(newInterval[1] < it[0]) 
            {
                ans.push_back(newInterval);
                newInterval = it;
            }
            
            //if newInterval lies within the currentIntervals
            else 
            {
                newInterval[0] = min(newInterval[0], it[0]);
                newInterval[1] = max(newInterval[1], it[1]);
            } 
        }

        //add the last Interval
        ans.push_back(newInterval);

        return ans;                                                                          
    }
};