// Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
// Note : Duration of the activity includes both starting and ending day.


// Example 1:

// Input:
// N = 2
// start[] = {2, 1}
// end[] = {2, 2}
// Output: 
// 1
// Explanation:
// A person can perform only one of the
// given activities.


    //Function to find the maximum number of activities that can
    //be performed by a single person.
    //function to compare activities based on their end time i.e, second parameter in pair
    static bool compare(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        //1st sort the activities on basis of their end time 
        //2nd then selct A0 activity and since the activities are now sorted on basis of end time we will selct those activity first which end soon, so we will iterate 
        //we need to ensure the activities are not overlapping by checking , next activity start time > last activity end time
       vector<pair<int, int>> activities(n);//declare a vector of pair datatype, kyuki hm bahut saare pairs ko vector k andar store karana chahte h
       //form the pair for start time and their corresponding end time of activities and put it in activities vector
       for(int i = 0; i<n ; i++){
           activities[i] = make_pair(start[i], end[i]);
       }
       //sort on basis of end time of activities 
       sort(activities.begin(), activities.end(), compare);
       
        int count = 1;//selecting A0
        int currendtime = activities[0].second;
        for(int i =0; i<n; i++){
            if(currendtime < activities[i].first ){
                count++;//activity fulfill non overlapping cond
                currendtime = activities[i].second;
            }
        }
        return count;
    }