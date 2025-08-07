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
        //jha par p ya q mil jae vahi par root return krdo
        // jab backtrack hokar ye value prev ancestors par jaegi tab agar kisi node n apne left or right child dono se not null response receive kiya iska mtlb that node is only lowest common ancestor kyuki p or q k path root node ki taraf wapis jaate hue isi node par phli baar mile
        //agar sirf ek left ya right child se not null value aaye iska mtlb dusra elem p or q is also located in the children node of that node jha par p or q mila to jha mila hai vahi lcs hoga 
        //to jo value return hoke aa rhi hogi vahi lca hogi
if(root == NULL)return NULL;
if(root == p|| root == q)return root;
TreeNode* leftcall = lowestCommonAncestor(root->left, p, q);
TreeNode* rightcall = lowestCommonAncestor(root->right, p, q);
if(leftcall != NULL && rightcall != NULL)return root;
if(leftcall != NULL)return leftcall;
return rightcall;
    }
};