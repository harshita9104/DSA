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
    bool isCompleteTree(TreeNode* root) {
        //hm level order traversal m har level ko left se right order m traverse to koi bhi tree complete binary tree tab nhi hoga jab traverse krte hue ek baar null val mil gya or uske baad not null agar present hai to simply return false
         queue<TreeNode*> q;
    q.push(root);
    bool foundNullChild = false;

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (curr->left) {
            if (foundNullChild) return false; // After null, we shouldn't find any children
            q.push(curr->left);
        } else {
            foundNullChild = true;
        }

        // Right child
        if (curr->right) {
            if (foundNullChild) return false;
            q.push(curr->right);
        } else {
            foundNullChild = true;
        }
    }
    return true;
       
    }
};