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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        //ek root ki poori subtree m check krna hai agar ek bhi 1 hai to NULL return nhi kr skte
        //or agar us root ki poori subtree m sab 0 hai to NULL return kardo 
        //or ye sab tabhi karna h jab root ki val 0 h
        //agar root ki val 1 hai to root hi return karna h
        //agar below cond m se ek bhi false hua yani ek bhi root ki val 1 hai to uska neg 0 hoga or cond false hogi or   root return hoga 
        if(!root->left && !root->right && root->val ==0)return NULL;
        return root;
    }
};