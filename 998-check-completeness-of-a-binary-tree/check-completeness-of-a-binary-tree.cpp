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
        queue<TreeNode*> q;
         bool flag = false;
         q.push(root);
        //agar null mila to isko true kardena 
        //null milne k baad agar koi not null value milti h level order traversal m iska mtlb binary tree is not complete binary tree
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL)flag = true;
            if(curr != NULL){
                if(flag == true){
                    return false;
                }else{
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return true;
    }
};