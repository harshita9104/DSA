class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> row;
        
        // Step 1: Count security devices in each row
        for(int i = 0; i < n; i++){
            int count = 0;
            for(auto c: bank[i]){
                if(c == '1'){
                    count++;
                }
            }
            row.push_back(count);
        }
        
        int ans = 0;
        int i = 0;
        int j = i + 1;
        
        // Step 2: Find pairs of rows with security devices
        while(j < row.size()){
            if(row[i] != 0 && row[j] != 0){
                // Both rows have devices - calculate beams between them
                ans += row[i] * row[j];
                i = j; // Move i to current j position
                j++;   // Move j to next position
            }
            else if(row[i] != 0 && row[j] == 0){
                // i has devices, j doesn't - skip j
                j++;
            }
            else if(row[i] == 0 && row[j] != 0){
                // i doesn't have devices, j does - move i to j
                i = j; // Fixed: move i to j instead of just i++
                j++;
            }
            else {
                // Both rows empty - move both (this case is covered by j++)
                j++;
            }
        }
        return ans;
    }
};