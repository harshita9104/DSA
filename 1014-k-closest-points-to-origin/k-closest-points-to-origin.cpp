class Solution {
public:
typedef pair<int, vector<int>> p;
struct cmp{
    bool operator()(p &a, p &b){
        return a.first < b.first;
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // farthest ko heap se remove krna to greatest dist wala point top pr hona chahiye
        // max heap bnega pair store krega {dist, {point coord}} 
        priority_queue<p,vector<p>, cmp> maxheap;
        for(vector<int> point : points){
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y;
            maxheap.push({dist,point});
            if(maxheap.size() > k){
                maxheap.pop();
            }
        }
        vector<vector<int>> result;
        while(!maxheap.empty()){
             result.push_back(maxheap.top().second);
             maxheap.pop();
        }
        return result;
    }
};