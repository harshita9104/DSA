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
        //level order traversal krenge 
        //or har level m jitne elem h utni baar ek inner loop chla kar last elem of a level store karke jaise hi vo inner loop khatam hoga 
        //us last elem of that level ko ans vector m daal do
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while(!q.empty()){
            int n = q.size();//no of nodes in curr level
            //is level k last elem ko nikalne k liye n times ek loop chlana hoga 
            TreeNode* node;
            while(n--){
                node = q.front();
                //is tarah se elem store ho jaega
                q.pop();
                //call left child and push it into queue first
                if(node->left != nullptr)q.push(node->left);
                if(node->right != nullptr)q.push(node->right);//is tarah hmne next level k elem daal diye
            }//ye loop current level k last elem ko node m store krke or next level k sare elem ko q m dalke khatam hoga
            ans.push_back(node->val);
        }
        return ans;
    }
};