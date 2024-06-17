class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        //(1<<k) isse keval kth position p 1 hoga or baki sab p 0
        //ab n ka & karenge (1<<k) k sath 
        //to agar kth position p  1 hua to 1 aajaega or 0 hua to 0
        return ((n &(1<<k)) != 0);
        //true means 0 k eq nhi h iska mtlb value 1 h at ith pos, mtlb set bit h 
        //false means 0 k eq h iska mtlb value 0 h at ith pos, mtlb set bit nhi h 
    }
};