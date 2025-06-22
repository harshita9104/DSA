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
    long long maxprod = INT_MIN;
    long long sum = 0;
    long long total =0;
    long long mod = 1e9+7;
    long long gettotal(TreeNode* root){
        if(root == NULL)return 0;
        total = root->val + gettotal(root->left) + gettotal(root->right);
        return total;//ab tak jitna trav hua uska sum return krdo jab backtrack hoga to ye val jaaegi upar wali line ka hi koi rec call ki return val h ye
    }
    long long solve(TreeNode* root, long long total){
        if(root == NULL)return 0;
        sum = root->val + solve(root->left, total) + solve(root->right, total);
        maxprod = max(sum*(total-sum), maxprod);
        return sum;
    }
//is q ko aise approach kr skte, ki sabse phle total cal karlo phir har ek node p jaao ab tak jitne node jma hue unko ek subtree mano,
//curr subtree ka jo sum hai use return karo taki next rec call m jab left or right subtree ka sum maange to usme ye returned value jaaye or curr subtree ka sum cal ho paye

    int maxProduct(TreeNode* root) {
        total = gettotal(root);
        sum = solve(root, total);
        return maxprod%mod;

    }
};