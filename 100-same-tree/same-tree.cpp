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
        if(p == NULL && q == NULL)return true;
        if(p == NULL || q == NULL)return false;//isme se koi ek not null hoga tabhi ye condition true hogi or false return hoga 
        //agar dono null hue to upar wali dono cond false hogi kuch nhi krna hoga : do nothing
        // queue<TreeNode*> q1;
        // queue<TreeNode*> q2;
        // q1.push(p);
        // q2.push(q);
        // while(!q1.empty() && !q2.empty()){
        //     TreeNode* curr1 = q1.front();
        //     TreeNode* curr2 = q2.front();
        //      q1.pop();
        //      q2.pop();
              if(p->val != q->val) return false;
        //     if(curr1->left && curr2->left){//when both are not null then this cond become true
        //         q1.push(curr1->left);
        //         q2.push(curr2->left);
        //     }else if(curr1->left || curr2->left){//when any one is not null and other is null , then true OR false is true 
        //     return false;
        //     //if both are null , false || false is false 
        //     // when both are null do nothing both the above  cond will be false 
        //     }
        //     if(curr1->right && curr2->right){//when both are not null then this cond become true
        //         q1.push(curr1->right);
        //         q2.push(curr2->right);
        //     }else if(curr1->right || curr2->right){//when any one is not null and other is null , then true OR false is true 
        //     return false;
        //     //if both are null , false || false is false 
        //     // when both are null do nothing both the above  cond will be false 
        //     }
        // }
        // //agar ye loop se bahar aa gya to dono sath m empty honi chahiye yani dono m same elem hone chahiye
        // return q1.empty() && q2.empty();
        return isSameTree(p->left, q->left)&& isSameTree(p->right, q->right);

    }
};