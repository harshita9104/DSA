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
    void dfs(TreeNode* root, unsigned long long index, int &count, unsigned long long &maxIndex) {
        if(root == NULL) return;

        count++;
        maxIndex = max(maxIndex, index);

        dfs(root->left, 2 * index, count, maxIndex);
        dfs(root->right, 2 * index + 1, count, maxIndex);
    }

    bool isCompleteTree(TreeNode* root) {
        int count = 0;
        unsigned long long maxIndex = 0;

        dfs(root, 1, count, maxIndex);

        return maxIndex == count;
    }
};
        //for a ith node i starting from 1 its left child will be at 2*i node and its right child will be at 2*i+1 node in array seq of level order traversal of tree
        // so first we will count total no of nodes in this tree
        //and if the node is null at any index then we need to keep that empty
        //so if the arr.size() > total nodes it means a index is empty in arr and tree is not complete
        