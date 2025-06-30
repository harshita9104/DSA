class StockSpanner {
public:
    StockSpanner() {
        
    }
    int index =-1;
    stack<pair<int, int>> st;
    vector<int> v;
    int next(int price) {
        index++;//it is given that calls will be made to this function so everytime a call is made 
        // price will be the price of current day 
        // and we need to find the span till today since this depends on the price of prev day we will push this pair of price and index in stack and everytime we are at today's price we will compare it with the prev price on stack top and we will pop the elem until we find nearest greater elem to left in price arr becoz the index of curr price - index of ngl = current span
        //no need of for loop calls will be made to this function one by one
        if(st.empty())v.push_back(-1);
        if(st.size()>0 && st.top().first > price )v.push_back(st.top().second);
        if(st.size()>0 && st.top().first <= price){
            while(st.size()>0 && st.top().first <= price)st.pop();
            //ye loop tak khatm hoga jab ya to st empty ho jae
            if(st.empty())v.push_back(-1);
            //ya greater elem mil jae
            if(st.size()>0 && st.top().first > price )v.push_back(st.top().second);
        }
        st.push({price, index});
        return index- v[index];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */