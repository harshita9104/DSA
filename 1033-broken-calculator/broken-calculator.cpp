class Solution {
public:
//if i start performing two operations on my start val each time i obtain 2 diff values , and then it can be done by bfs calls but it will be too many calls and even after obtaining target we dont know if that is min no. of operations or not
//so piche se start karo mtlb , target se startVal par pahuchne ka try kro
//so ab operations honge 
//+1 and /2 

//or is q m adv ye h ki divide by 2 tabhi kr skte jab val even hai to jab odd hoga +1 kardo
    int brokenCalc(int startValue, int target) {
        if(startValue == target)return 0;
        if(startValue > target)return startValue - target;
        int count =0;
        while(target != startValue){
            if(target % 2 == 0 && target > startValue ) target = target/2;
        else target = target+1;
        count = count +1;
        }
        return count;
    }
};