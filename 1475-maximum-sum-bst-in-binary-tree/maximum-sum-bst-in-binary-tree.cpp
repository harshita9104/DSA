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
    int maxSum = 0;
    
    // Returns {isBST, sum, minVal, maxVal}
    vector<int> helper(TreeNode* root) {
        if (root == NULL) {
            return {1, 0, INT_MAX, INT_MIN}; // {isBST, sum, minVal, maxVal}
        }
        
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        
        // Your BST validation logic: check if current subtree is valid BST
        bool isValidBST = left[0] && right[0] && 
                         (root->left == NULL || left[3] < root->val) && 
                         (root->right == NULL || right[2] > root->val);
        
        if (isValidBST) {
            // Your sum calculation logic
            int currSum = root->val + left[1] + right[1];
            maxSum = max(maxSum, currSum);
            
            // Calculate bounds for parent
            int minVal = (root->left == NULL) ? root->val : left[2];
            int maxVal = (root->right == NULL) ? root->val : right[3];
            
            return {1, currSum, minVal, maxVal};
        } else {
            // Not a BST, but continue checking subtrees (your dfs logic)
            return {0, 0, 0, 0};
        }
    }
    
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        helper(root);
        return maxSum;
    }
};