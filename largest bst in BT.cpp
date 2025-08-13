// You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

// Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

// Examples :

// Input: root = [5, 2, 4, 1, 3]
// Output: 3
// Explanation:The following sub-tree is a BST of size 3

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
public:
    int countmax = 0; // stores size of largest BST found so far
    
    // Function to get the size of a given tree
    int size(Node* root) {
        if (!root) return 0;
        return 1 + size(root->left) + size(root->right);
    }
    
    // Function to check if a tree is a valid BST
    bool isvalid(Node* root, int minval, int maxval) {
        // Base case: empty tree is a valid BST
        if (!root) return true;

        // BST property check: current node must be strictly between minval and maxval
        if (root->data <= minval || root->data >= maxval) return false;

        // Recursively check left and right subtrees with updated constraints
        return isvalid(root->left, minval, root->data) &&
               isvalid(root->right, root->data, maxval);
    }
    
    // Function to check each node's subtree and update countmax
    void check(Node* root) {
        if (!root) return;

        // If current subtree is a valid BST
        if (isvalid(root, INT_MIN, INT_MAX)) {
            // calculate its size
            int curr_size = size(root);
            // update largest size
            countmax = max(countmax, curr_size);
        }

        // Even if current root is not BST, there may be BST in left or right subtree
        check(root->left);
        check(root->right);
    }
    
    int largestBst(Node *root) {
        check(root);
        return countmax;
    }
};
