/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; 
Given a binary tree with n nodes and two node values, a and b, your task is to find the minimum distance between them. The given two nodes are guaranteed to be in the binary tree and all node values are unique.

Examples :

Input: Tree = [1, 2, 3]
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: We need the distance between 2 and 3. Being at node 2, we need to take two steps ahead in order to reach node 3. The path followed will be: 2 -> 1 -> 3. Hence, the result is 2. 
Input: Tree = [11, 22, 33, 44, 55, 66, 77]
        11
      /   \
     22  33
    /  \  /  \
  44 55 66 77
a = 77, b = 22
Output: 3
Explanation: We need the distance between 77 and 22. Being at node 77, we need to take three steps ahead in order to reach node 22. The path followed will be: 77 -> 33 -> 11 -> 22. Hence, the result is 3.

*/

class Solution {
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
   // LCA dhundhne ka function, same as your code
Node* findLCA(Node* root, int a, int b){
    if(root == NULL) return NULL;
    if(root->data == a || root->data == b) return root;
    Node* left = findLCA(root->left, a, b);
    Node* right = findLCA(root->right, a, b);
    if(left != NULL && right != NULL) return root;
    if(left != NULL) return left;
    if(right != NULL) return right;
    return NULL;
}

// solve function, path sum from root to p, pass by value sum, p is node value not pointer
int solve(Node* root, int p, int sum){
    // agar root NULL hai to path exist nahi karta, return -1
    if(root == NULL) return -1;
    // agar current node hi p hai, to sum return kardo
    if(root->data == p) return sum;

    // left subtree me search karo, sum+1
    int leftsum = solve(root->left, p, sum+1);
    if(leftsum != -1) return leftsum; // agar left me mil gaya to wahi return kardo

    // right subtree me search karo, sum+1
    int rightsum = solve(root->right, p, sum+1);
    if(rightsum != -1) return rightsum; // agar right me mil gaya to wahi return kardo

    // agar kahin nahi mila to -1 return kardo
    return -1;
}

// main function to find distance between a and b
int findDist(Node* root, int a, int b) {
    // LCA nikal lo pehle
    Node* lca = findLCA(root,a,b);

    // lca se a tak ka distance
    int a_sum = solve(lca, a, 0);

    // lca se b tak ka distance
    int b_sum = solve(lca, b, 0);

    // total distance is sum of both
    return a_sum + b_sum;

    }
};
