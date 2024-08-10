// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted

//max heap banao , kyuki farther dist wale points ko htana hai to vo top p honge
//basis of sorting in heap will be euclidean dist which can be cal as x2 +y2 as the relative order remains same even if sq root is not taken
//also store the pair of {x,y} with the dist as the k closest dist points in heap will have to retur their corresponding points 
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
     priority_queue<pair<int, pair<int, int>>> maxheap;//dist bw x &y, (x,y)
     for(int i =0; i< arr.size(); i++){
        maxheap.push(make_pair(arr[i][0]*arr[i][0]+ arr[i][1]*arr[i][1],make_pair(arr[i][0],arr[i][1])));//{(x2+y2),{x,y}}
        if(maxheap.size() >k){
            maxheap.pop();
        }
     }
     vector<vector<int>> ans;
     while(maxheap.size()>0){
    ans.push_back({maxheap.top().second.first,maxheap.top().second.second});
    maxheap.pop();
     }
     return ans;
    }