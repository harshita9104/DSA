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
    string solve(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*> &res){//by ref pass kiya kyuki last rec call ki val ko aage leke jana h
        if(root == NULL)return "N";
        string s = to_string(root->val) + "," + solve(root->left,mp,res) +","+ solve(root->right, mp, res);
        if(mp[s] == 1)res.push_back(root);
        mp[s]++;
        return s;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // jaise jaise tree m traverse kar rhe nodes ko string m add krte jaao 
        //or ek map bnalo string or count of string occ ka 
        //jaise hi phle dekhi hui string yaani jiska count 1 se jyada hai , phirse dekho to us string k root ko res m daaldo
        //string ki tarah store karke check krna ki phle dekhi h kya assan h
        //map of string and int to keep track of occ of str
        unordered_map<string, int> mp;
        vector<TreeNode*> res;//vector to store root node of such multiple occ subtrees
        solve(root, mp, res);
        return res;

    }
};