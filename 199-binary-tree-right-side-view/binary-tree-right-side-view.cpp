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
    void dfs(TreeNode* root, int level, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        if(ans.size() <level){
            ans.push_back(root->val);
        }
        //phle right ko call krke saare right wale elem daaldo har baar right m hi next level par call ho rha h 
        //jab right m end m pahuch kr backtrack karke left m jaenge tab vo elem jinka level hmare ab tak k covered level se jyada hai tabhi hm left wale node ko ans m daalenge
        dfs(root->right, level +1, ans);
        dfs(root->left, level +1, ans);

    }
    vector<int> rightSideView(TreeNode* root) {
        //level order traversal krenge 
        //or har level m jitne elem h utni baar ek inner loop chla kar last elem of a level store karke jaise hi vo inner loop khatam hoga 
        //us last elem of that level ko ans vector m daal do
        if(root == nullptr){
            return {};
        }
        // queue<TreeNode*> q;
        vector<int> ans;
        // q.push(root);
        // while(!q.empty()){
        //     int n = q.size();//no of nodes in curr level
        //     //is level k last elem ko nikalne k liye n times ek loop chlana hoga 
        //     TreeNode* node;
        //     while(n--){
        //         node = q.front();
        //         //is tarah se elem store ho jaega
        //         q.pop();
        //         //call left child and push it into queue first
        //         if(node->left != nullptr)q.push(node->left);
        //         if(node->right != nullptr)q.push(node->right);//is tarah hmne next level k elem daal diye
        //     }//ye loop current level k last elem ko node m store krke or next level k sare elem ko q m dalke khatam hoga
        //     ans.push_back(node->val);
        // }
        
        //DFS
        int level;
        dfs(root, 1, ans);
        return ans;
    }
};