/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        
       TreeNode*  leftn = lowestCommonAncestor(root->left, p, q);
       TreeNode*  rightn = lowestCommonAncestor(root->right, p, q);

        if(leftn != NULL && rightn != NULL){
            return root;//it means this root has got p and q from its  left and right child calls so this is only my lcs 
        }
        if(leftn != NULL && rightn == NULL){
            return leftn; //becoz it is given tht p and q both exists since we got null from right child call and a not null value from leftn which store the root node  where we have found our p or q so that node is only lca coz in its child nodes we will find the other q or p.
        }
        // if(leftn == NULL && rightn != NULL)
            return rightn; 
        
    }
};