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
bool isIdentical(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL && root2 == NULL)return true;
    if(root1 == NULL || root2 == NULL)return false;//if the whole subroot values exist but in tree their are more children of those nodes then in this case this condn will return false
    if(root1->val != root2->val)return false;//this will be checked for every node in subsequent rec calls where root node will be what we will pass in rec call, we will check now if the struc is same or not by checking if left child is same as left child or not
    //both left child shd match , both right child shd match
    return isIdentical(root1->left, root2->left) && isIdentical(root1->right,root2->right);

}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL)return true;
         if(root == NULL || subRoot == NULL)return false;//agar koi ek null or dusra not null
         if(root->val == subRoot->val){//this will be checked for every node in subsequent recursive calls
            if(isIdentical(root, subRoot))return true;//agar true hai yani poora identical subtree mil gya h to hi true return krenge nhi mila to further explore krenge 
         }
         
         //check in left subtree if found in left subtree then no need to check in right subtree
         int isleftsubtree = isSubtree(root->left, subRoot);
         if(!isleftsubtree){
            //agar left subtree m mil gya identical to right m search krne ki jarurat nhi
            return isSubtree(root->right, subRoot);
         }

return true;
    }
};