//     Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

 

// Example 1:


// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
// Example 2:

// Input: root = [1,2]
// Output: 1

    //O(n^2)
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right) +1 ;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        //2 cases 
        //1st when root node is part of diameter
        int currdiam = height(root->left) +height(root->right) ;
        //when max diameter of our tree exist in left or right subtree
        int leftdiam = diameterOfBinaryTree(root->left);
        int rightdiam = diameterOfBinaryTree(root->right);
        int diam = max(currdiam, max(leftdiam, rightdiam));
         return diam;
    }
    //O(n) 
    //since we are making a recursive call for all the subtress while calculating daim so no need to call height function alg se we can calculate (diam, height) for a tree or subtree at same time
    pair<int,int> helper(TreeNode* root){
        if(root == NULL){
            return make_pair(0,0);
        }
        pair<int, int> leftinfo = helper(root->left);//(LD, LH)
        pair<int, int> rightinfo = helper(root->right);//(RD, RH)
 //assume karlo ki left subtree or rightsubtree ka diam or height hme ye functions return karke denge to phir aage induction step m kya krna hai leftsubtree or rightsubtree ki height or diam k sath taaki hm finalht or finaldiam nikal ske tree k liye
      int currdiam = leftinfo.second + rightinfo.second ;
      int finaldiam = max(currdiam , max(leftinfo.first, rightinfo.first));//for the case jab ho skta h diam (max dist bw 2 leaf nodes) lie in any of the leftsubtree or rightsubtree
      int finalheight = max(leftinfo.second, rightinfo.second) + 1;
      return make_pair(finaldiam, finalheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).first;

    }