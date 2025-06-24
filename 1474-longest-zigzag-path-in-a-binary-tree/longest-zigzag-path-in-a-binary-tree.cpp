/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int longest = 0;
void solve(TreeNode* root, int steps, bool goleft){
    //bool goleft btata hai ki left jana h or agar ye false h to it means right jana h 
    if(root == NULL)return;
    longest = max(longest,steps);
    if(goleft == true){
        solve(root->left, steps+1, false);//mtlb jana left m tha or mai left m hi gyi to steps++ or ab next right jana hai to goleft ko false
        solve(root->right, 1, true);
    }else{
        solve(root->left, 1, false);//mtlb jana right m tha or mai left m hi gyi to steps or
        solve(root->right, steps+1, true);
    }
}
    int longestZigZag(TreeNode* root) {
        int steps =0;
        solve(root, steps, true);
        solve(root, steps, false);
        return longest;
        
    }
};