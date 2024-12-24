// ### Explanation to Interviewer

// #### Problem:
// We need to determine if a binary tree is height-balanced. A binary tree is considered height-balanced if, for every node in the tree, the height difference between its left and right subtrees is no more than one.

// #### Thought Process:

// 1. **Definition of Balance:**
//    - A tree is balanced if, for every node, the difference in heights between the left and right subtrees is at most 1.

// 2. **Recursive Height Calculation:**
//    - To check if a tree is balanced, I calculate the height of the left and right subtrees for each node.
//    - While calculating the height, if I find that any subtree is unbalanced (i.e., the height difference is greater than 1), I immediately return -1 to indicate that the tree is not balanced.

// 3. **Optimized Approach:**
//    - Instead of calculating the height of the subtrees separately and then checking the balance condition (which would result in redundant height calculations), I integrated the balance check within the height calculation.
//    - By returning -1 as soon as an unbalanced subtree is detected, I avoid further unnecessary calculations.

// #### Optimization from Brute Force:
// The brute force approach would involve:
// 1. Calculating the height of each subtree multiple times, resulting in redundant computations.
// 2. Checking the balance condition separately for each node.

// To optimize:
// - I used a single recursive function to both calculate the height and check the balance condition simultaneously.
// - This ensures that each node is processed only once, leading to an overall time complexity of **O(n)**, where `n` is the number of nodes in the tree.

// ### Time Complexity:
// - **O(n):** Each node is visited once, and the height is calculated while checking the balance condition.
  
// ### Space Complexity:
// - **O(h):** The space complexity is determined by the height of the tree due to the recursive call stack.

// ### Optimized Code with Comments:
// ```cpp
class Solution {
public:
    // Function to calculate height and check balance
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0; // Base case: empty tree has height 0
        }

        // Recursively calculate the height of the left subtree
        int lh = height(root->left);
        if (lh == -1) {
            return -1; // If left subtree is unbalanced, propagate -1 upwards
        }

        // Recursively calculate the height of the right subtree
        int rh = height(root->right);
        if (rh == -1) {
            return -1; // If right subtree is unbalanced, propagate -1 upwards
        }

        // Check the balance condition at the current node
        if (abs(lh - rh) > 1) {
            return -1; // If the current node is unbalanced, return -1
        }

        // Return the height of the current node
        return max(lh, rh) + 1;
    }

    // Function to check if the tree is balanced
    bool isBalanced(TreeNode* root) {
        return height(root) != -1; // Tree is balanced if height function does not return -1
    }
};


