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
bool solve(TreeNode* p, TreeNode* q){
    if(p == NULL && q == NULL)return true;
    if(p == NULL || q == NULL)return false;
    //few conditions need to be true for a tree to be symmetric
    //the value of p and q need to be eq after curr root in rec call is checked we need to check this for their left and right child
    //p or q dono eq hai or ek dusre ki mirror images h
    // ab check krna hai ki p ka left child or q ka right child eq hona chahiye
    //and p ka right child or q ka left child equal hona chahiye
    //ye teeno condition true hona chahiye
    bool check = p->val == q->val;
    bool leftcheck = solve(p->left, q->right); 
     bool rightcheck = solve(p->right, q->left); 
     return check&&leftcheck&&rightcheck;
}
    bool isSymmetric(TreeNode* root) {
      return solve(root->left, root->right);
    }
};