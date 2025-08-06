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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        int ans = 0;
        while(!q.empty()){
           int level = q.size();
           while(level--){
            TreeNode* curr = q.front();
            q.pop();
            if(curr != NULL)ans =curr->val;//level k last wala elem hi last m ans m hoga ye level wala loop khtm hote hi hm usko res vector m push krdenge
            if(curr->left != NULL)q.push(curr->left);
             if(curr->right != NULL)q.push(curr->right);

           }
           res.push_back(ans);
        }
        return res;
    }
};