//leetcode - 236 
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


//function to get the path from root to node n and store it in vector
    bool rootToNode(TreeNode* root, TreeNode* n, vector<TreeNode*> &path){
        if(root == NULL){
            return false;
        }
        path.push_back(root);
 //maanlo ki currnode se hi hoke path guzarta hai n tak ka to currnode ko push kardo vector m
        if(root->val == n->val){
  //phle check karlo kahi curr node hi vo val to nhi h jisse hm dhoondh rhe h
            return true;
        }
         //left or right subtree m call lagao, agar return nhi hua h true to
        bool isleft = rootToNode(root->left, n ,path);//left child ko call lgate hi vo root bn jaega us function call m or path m push ho jaega or agar isme n mila to path mil jaega hme or nhi mila to vo pop ho jaega
       bool isright = rootToNode(root->right, n ,path);
       //ab agar left or right dono m hi n nhi milta h , jaise hm kisi subtree k last node p or uske left or right se null return hua to us node ko path se htana pdega or phir us root node k right child ko dekhenge ki vo n k eq h kya vo bhi nhi hua to root node ko hi htana pdega or dusre subtree m dekhna pdega
       //par agar ek bhi child left ya right child true return karta hai root node path m included hoga or return true kardenge ki path mil gya hai or jin jin node se path mila hai vo vector m already push ho gye h or jha se path nhi mila vo pop ho gye h
       if(isleft || isright){
        return true;
       }else{
        path.pop_back();
        return false;
       }


        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;//path from root to p
      vector<TreeNode*> path2;//path from root to q
     

      rootToNode(root, p,path1);//function call to get path of p from root
       rootToNode(root, q ,path2);
       //now we will traverse both the path and the moment the values of the paths become different (!=) it means they are diverged now and we have obtained lowest common ancestor earlier we will keep lca updating till we are getting same values of both paths
        TreeNode* lca = NULL;
        for (int i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i] == path2[i]) {
                lca = path1[i];
            } else {
                break;
            }
        }
        return lca;
    };


//optimised, SC- O(1)
Node* lowestCommonAncestor(Node* root, int p, int q) {
        if(root == NULL){
            return NULL;
        }
        if(root->data == p || root->data == q){
            return root;//this is done to cover example 2 jha p 5 khud lca h 
        }
        Node* leftlca = lowestCommonAncestor(root->left, p, q);
        Node* rightlca = lowestCommonAncestor(root->right, p, q);
        //lca vo phla node hoga jiske left or right subtree se not null value return hogi at that time vhi node lca h jiska left or right valid values reurn kiya
        if(leftlca != NULL && rightlca != NULL){
            return root;
        }
        //otherwise : agar kisi root node ka koi ek bhi left ya right not null return kare to further usi valid value ko retur karna h 
        return leftlca == NULL ? rightlca : leftlca;
};