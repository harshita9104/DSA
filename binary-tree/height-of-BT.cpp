class Solution{
    public:
    //Function to find the height of a binary tree.(max dist bw leaf and root node)
    int height(struct Node* node){
        // code here 
        if(node == NULL){
            return 0;//when a node is null it doesnt exist its height is 0
        }
        int left = height(node->left);//height of left subtree
        int right = height(node->right);//height if right subtree
        return max(left,right) +1;
    }
};