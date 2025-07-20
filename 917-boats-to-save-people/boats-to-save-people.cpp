class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i =0;
        int j = people.size()-1;
        int boats=0;
        int n = people.size();
        vector<bool> inside(n, false);
        //jab 1 boat m 2 log daalne h 
        while(i<j){
            
            if(people[i] + people[j] <=limit){
                boats++;
                inside[i] = inside[j] = true;
                i++;
                j--;
                
            }else if(people[i] + people[j] >limit){
                j--;
            }else{
                continue;
            }
        }
        //agar pair bn paate to upar ban gye or un pairs ko inside boat true mark kar diya 
        //ab jo bach gye uko indi boat m daldo
        for(int i =0; i<n; i++){
            if(inside[i] == false && people[i] <= limit){
                boats++;
            }
        }
        return boats;
    }
};