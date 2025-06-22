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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        // Both empty
        if(p == NULL && q == NULL) return true;
        // One empty, one not
        if(p == NULL || q == NULL) return false;

        q1.push(p);
        q2.push(q);

        // Both queues must be same size at all times
        while(!q1.empty() && !q2.empty()){
            TreeNode* curr1 = q1.front();
            TreeNode* curr2 = q2.front();
            q1.pop();
            q2.pop();

            // Values must match
            if(curr1->val != curr2->val) return false;

            // Left children: both null is fine, one null is not
            if(curr1->left && curr2->left) {
                q1.push(curr1->left);
                q2.push(curr2->left);
            } else if(curr1->left || curr2->left) {
                return false;
            }

            // Right children: both null is fine, one null is not
            if(curr1->right && curr2->right) {
                q1.push(curr1->right);
                q2.push(curr2->right);
            } else if(curr1->right || curr2->right) {
                return false;
            }
        }

        // Both queues must be empty for trees to be the same
        return q1.empty() && q2.empty();
    }
};