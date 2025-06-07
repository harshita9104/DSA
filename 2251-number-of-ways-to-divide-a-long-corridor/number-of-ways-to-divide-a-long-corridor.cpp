class Solution {
public:
    int numberOfWays(string corridor) {
        //ek corridor ko m dividor install karne hai , har ek dividor ek section bnayega or har section m exactly two seats honi chahiye , ab exactly 2 seats hone k liye total no of seats in a corridor shd be even
        const int MOD = 1000000007;
        
        vector<int> indexes;
        for(int i =0; i<corridor.size(); i++){
            if(corridor[i] == 'S'){
                indexes.push_back(i);
            }
        }
        int totalseats = indexes.size();
        if(totalseats == 0 || totalseats % 2 == 1){//that is total seats are odd cant have each 2 seats in each section
        return 0;
        }
        if(totalseats == 2){
            return 1;
        }
        //this stores no of ways
        long long result =1;
        //count no of plants between current pair's end and next pair's start
        for(int i = 1; i< totalseats -2; i +=2){
            //i will point towards the end of pair of seats
            //so we will calculate no of plants between end of pair of seats and start of next pair
            //We want to find gaps between pairs, so:

// i = 1: End of pair 1 (seats[1] = position 2)
// i = 3: End of pair 2 (seats[3] = position 6)
// i = 5: End of pair 3 (seats[5] = position 9)
// i += 2 jumps from one pair's end to the next pair's end!

            int ways = indexes[i+1] - indexes[i];//indexes[i+1] is start of next pair and indexes[i] will be end of a pair
            //when you have multiple independent choices, you multiply the number of ways.
            //Because for each choice in Gap 1, you can make any choice in Gap 2, and for each combination of Gap 1 & 2, you can make any choice in Gap 3
             result = (result*ways)%MOD;
            
        }
        return result;
    }
};