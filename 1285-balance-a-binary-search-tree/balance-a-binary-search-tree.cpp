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
TreeNode* solve(int start, int end, vector<int>& nums) {
        // base case: agar start > end ho gaya to NULL return karo
        if(start > end) return NULL;
        
        // mid nikaalo, har call ka apna mid hoga, isliye local variable
        int mid = start + (end - start)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        // left subtree build karo
        root->left = solve(start, mid-1, nums);
        // right subtree build karo
        root->right = solve(mid+1, end, nums);
        
        return root;
    }
void inorder(TreeNode* root, vector<int> &nums){
    if(root == NULL)return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);

}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
         int start = 0;
        int end = nums.size()-1;
        return solve(start, end, nums);
    }
};