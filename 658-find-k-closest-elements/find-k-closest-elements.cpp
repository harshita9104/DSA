class Solution {
public:
    typedef pair<int, int> p;
    // custom comparator for max-heap: diff descending, value descending
    struct cmp {
        bool operator()(p& a, p& b) {
            if(a.first == b.first) return a.second < b.second; // value descending
            return a.first < b.first; // diff descending
        }
    };
    //maxheap me k closest elements store karenge, har naye element pr agar heap size > k ho jaye to max/farthest wala pop kar denge
// end me heap me k closest elements bachenge
// result ascending order me sort karke return karenge

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // max heap, so farthest element will remove when size > k
        priority_queue<p, vector<p>, cmp> maxheap;
        for(int i = 0; i < arr.size(); i++) {
            int diff = abs(arr[i] - x);
            maxheap.push({diff, arr[i]});
            if(maxheap.size() > k) {
                maxheap.pop();
            }
        }
        // get all elements from heap
        vector<int> result;
        while(!maxheap.empty()){
            result.push_back(maxheap.top().second);
            maxheap.pop();
        }
        // sort result ascending as required
        sort(result.begin(), result.end());
        return result;
    }
};