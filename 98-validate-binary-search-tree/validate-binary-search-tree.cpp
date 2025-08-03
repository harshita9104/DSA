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
bool solve(TreeNode* root, long long minval, long long maxval){
    // if(root->left == NULL && root->right == NULL)return true;
    if(root == NULL)return true;
    //curr root valid h kya ye check krlo
    if(root->val >= maxval || root->val <= minval)return false;//bst rule follow nhi kr rha
    //ab iske left or right subtree  ko call krdo complete tree k valid hone k liye left or right subtree ka valid hona jarruri h dono subtree true return krne chahiye
    return solve(root->left, minval, root->val)&&solve(root->right, root->val, maxval);
}
    bool isValidBST(TreeNode* root) {
        //in a BST we have upper bound and lower bound for each node , for the root node of the tree there is no such limit so lower bound can be INT_MIN, and upper bound can be INT_MAX, 

    //left child ko call karte time upper bound pass karo root ki val , and lower bound will be the default val if not specified
    //right child ko call krte waqt lower bound pass kro root ki val
    //agar kisi bhi subtree m false return hua to false return krdo
    //ek root k valid bst hone k liye right subtree m sab ussse greater  && left subtree m sab usse smaller hone jaruri h, to dono subtree ko ek sath call hoga
    // or jab call hoke jaega to us recursive call m curr root valid h kya check krne k liye root ki val lower bound se badi nhi h || upper bound se choti nhi h to false return krdenge 
    //agar ek rec acll m bhi false return hua to bst nhi h tree 
     // Use long long limits to avoid edge case issues
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};