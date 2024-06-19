//Given a non-negative number N. The problem is to set the rightmost unset bit in the binary representation of N.


int setBit(int N)
    {
      
          N = N | N +1;
          return N;
       
      
    }