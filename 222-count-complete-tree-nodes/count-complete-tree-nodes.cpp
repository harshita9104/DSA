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
    int countNodes(TreeNode* root) {
        if(root == NULL)return 0;
        queue<TreeNode*> q;
        int count =0;
        
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();//ek ek karke bfs traversal m har node q k front par aayega or hm usse count karelenge
            count++;
            q.pop();
            if(curr->left != NULL)q.push(curr->left);
            if(curr->right != NULL)q.push(curr->right);
        }
        return count;
    }
};