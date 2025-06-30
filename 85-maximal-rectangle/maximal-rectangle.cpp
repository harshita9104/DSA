
class Solution {
public:
    // Find index of next smaller to left for each bar
    vector<int> nsl(vector<int> &v){
        stack<pair<int, int>> s; // value, index
        vector<int> ind;
        for(int i =0; i<v.size(); i++){
            // Pop until we find a smaller element
            while(!s.empty() && s.top().first >= v[i]) s.pop();
            if(s.empty()) ind.push_back(-1); // No smaller to left
            else ind.push_back(s.top().second);
            s.push({v[i], i});
        }
        return ind;
    }
    
    // Find index of next smaller to right for each bar
    vector<int> nsr(vector<int> &v){
        stack<pair<int, int>> s; // value, index
        vector<int> ind(v.size());
        for(int i = v.size()-1; i >=0; i--){
            // Pop until we find a smaller element
            while(!s.empty() && s.top().first >= v[i]) s.pop();
            if(s.empty()) ind[i] = v.size(); // No smaller to right
            else ind[i] = s.top().second;
            s.push({v[i], i});
        }
        return ind;
    }
    
    // Largest Rectangle in Histogram
    int mah(vector<int> &v){
        vector<int> right = nsr(v);
        vector<int> left = nsl(v);
        vector<int> width(v.size());
        int area = 0;
        for(int i =0; i<v.size(); i++){
            width[i] = right[i] - left[i] - 1;
            area = max(area, width[i] * v[i]);
        }
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> v(cols, 0);
        int largest_area = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '0') v[j] = 0;
                else v[j] += 1;
            }
            largest_area = max(largest_area, mah(v));
        }
        return largest_area;
    }
};