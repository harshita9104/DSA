// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    // Helper function to perform DFS and find all root-to-leaf paths with the given sum
    bool flag = false;
    //here pathsum is passed by value so that each recursive call maintaines a copy of pathsum and when i backtrack on prev node it is on prev rec call so pathsum val in this rec call will have its own copy that is the val till curr node
    
    //there is no mess when we backtrack to explore other paths becoz when pass by ref org var gets changed in each rec call then modifying pathsum would be difficult during backtracking

    void solve(TreeNode* root, int pathsum,  int targetSum) {
        if (root == NULL) return; // Base case: If node is null, just return

        // Add current node's value to pathsum and path
        pathsum += root->val;
        // path.push_back(root->val);

        // If the current node is a leaf node (no left and right children)
        // and the pathsum equals the targetSum, add the path to result
        if (root->left == NULL && root->right == NULL && pathsum == targetSum) {
           flag = true;
        } else {
            // Continue DFS on left and right children
            solve(root->left, pathsum,  targetSum);
            solve(root->right, pathsum,  targetSum);
        }

        // Backtrack: remove the current node from path before returning
        // path.pop_back();
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
       

        // Start DFS only if the tree is not empty
        // Mistake correction: Do not access root->val if root is NULL
        solve(root, 0, targetSum);
        return flag;
        
    }
};