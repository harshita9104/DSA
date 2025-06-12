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
    // Recursive function to build the tree
    // start, end: boundaries of current inorder subarray
    // idx: current position in preorder array (passed by reference)
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx){
        
        // Base case: if start > end, no elements left to process
        // This means we've reached an empty subtree
        if(start > end){
            return nullptr;
        }
        
        // The current root is always the element at idx position in preorder
        // Preorder visits: root -> left -> right, so current idx is always root
        int rootval = preorder[idx];
        
        // Find the position of root in inorder array
        // This divides inorder into left and right subtrees
        int i = start;
        for(; i <= end ; i++){
            if(inorder[i] == rootval) break;  // Found root position
        }
        
        // Move to next element in preorder for next recursive call
        // We increment idx after finding root but before building subtrees
        idx++;
        
        // Create the root node with current root value
        TreeNode* root = new TreeNode(rootval);
        
        // Build left subtree recursively
        // Left subtree elements in inorder: from start to i-1
        // In preorder, left subtree elements come immediately after root
        root->left = solve(preorder, inorder, start, i-1, idx);
        
        // Build right subtree recursively  
        // Right subtree elements in inorder: from i+1 to end
        // In preorder, right subtree elements come after all left subtree elements
        root->right = solve(preorder, inorder, i+1, end, idx);
        
        // Return the constructed root
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();  // Get size of arrays
        int idx = 0;              // Initialize preorder index to 0
        
        // Start recursive construction with full inorder range [0, n-1]
        return solve(preorder, inorder, 0, n-1, idx);
    }
};