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
    void inorder(TreeNode* root, vector<int>& node) {
        if(root == NULL) return;
        inorder(root->left, node);
        node.push_back(root->val);
        inorder(root->right, node);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> node1, node2, merged;
        inorder(root1, node1);
        inorder(root2, node2);
        int i = 0, j = 0;
        // merge two sorted arrays
        while(i < node1.size() && j < node2.size()) {
            if(node1[i] < node2[j]) {
                merged.push_back(node1[i++]);
            } else {
                merged.push_back(node2[j++]);
            }
        }
        while(i < node1.size()) merged.push_back(node1[i++]);
        while(j < node2.size()) merged.push_back(node2[j++]);
        return merged;
    }
};