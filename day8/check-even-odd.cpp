string oddEven(int N){
        //for all the odd numbers the righmost bit is 1
        //for all the even numbers rightmost bit is 0
        if((N & 1) == 0){
            return "even";
        }else{
           return "odd"; 
        }
    }