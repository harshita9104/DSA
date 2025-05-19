class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int l =0;
        int h = n-1;
        int boats = 0;
        while(l<=h){
            if(people[l] + people[h] <= limit){
                
                l++;
                h--;
            }else {
                // Heaviest person goes alone
                h--;
            }
            boats++;

        }
        //after this we have obtained the no of boats that will take 2 people now the no. of ppl remaining cant be paired up as they exceed tht limit so boat will take them individually
        
        return boats;
    }
};