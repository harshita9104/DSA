class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //gas stores ki us gas station p kitna gas fill kr sjte
        //cost stores ki us gas station se kahi jane pr kitna consume hoga
        //if total gas avail t all the gas station < gas req to travel all gas station then it is not possible to travel all return -1;
        int totalgas =0;
        int totalcost =0;
        for(int i=0; i<cost.size(); i++){
            totalcost += cost[i];
            totalgas += gas[i];
        }
        //step 1 determine if a soln is even possible or not 
        if(totalgas < totalcost)return -1;
       
       //step 2 : if yes then apply our greed criteria that can we start from a particular position, 
       //start iterating thr arr ,  but in travel if anywhere the gain-cost <0 tehn we cant continue journey so discard this start point as we wont be able to complete if we start from here
       //now start from next avail posistion 
        int start =0;
        int  currgain =0;
        for(int i = 0; i< cost.size(); i++){
            currgain += gas[i]-cost[i];
            if(currgain< 0){
             currgain =0;
             start = i+1;
            }
            //ab agar next index se shuru krne par currgain pos rhta hai it means it can be a starting point since soln to possible hai hi if overall gain is pos
        }
        return start;
        
             
    }
};