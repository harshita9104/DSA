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
int solve(TreeNode* root, int &ans){//by ref pass kro har rec call m ans ki max val jaegi or badi val mili to update ho jaega 
    if(root == NULL)return 0;
    int left = solve(root->left,ans);
    int right = solve(root->right, ans);
    ans = max(ans, left+right);//isme curr root ko include krke ek curvy path bna h ab ye left or right height bhi to cal karni h 
    //max se sabse lamba curve pta chl jaega konsa h it may or may not include the root of the whole tree
    //ab kyuki hm rec calls m left or right subtree ki height cal kr rhe to hme right or left ka max +1 return krna hoga 
    //kyuki har node k left or right child h to us  node ki height will be max of left or right+1
    return 1+max(left,right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        int ans = INT_MIN;
       solve(root, ans);
        return ans;
    }
};