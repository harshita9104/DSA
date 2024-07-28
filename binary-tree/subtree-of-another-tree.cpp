//leetcode 572
// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.




 bool isIdentical(TreeNode* root1, TreeNode* root2){
        //BASE CASE
        if(root1 == NULL && root2 == NULL){
            //agar dono null h to identical hai
            return true;
        }else if(root1 == NULL || root2 == NULL){
            //agar dono m se ek bhi NULL hai to compare hi nhi kr skte
            return false;
        }
        if(root1->val != root2->val){//val k liye check karenge pointer to hmesha not eq hi honge
            return false;
        }
        //dono left or right part k recursive call n true return kiya tabhi isIdentical true return karega kyuki root1 or root2 ki tree ko identical hone k liye har node ki value or poora structure same hona chahiye agar same nhi hua to isIdentical false return kar dega nhi to bar bar left or right ko recursive call krte-krte jab vo dono null node tak pahuch jaenge iska mtlb abhi tak poora tree same tha or true return ho jaega base case p
        return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);


    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //BASE CASE
        if(root == NULL && subRoot == NULL){
            //agar dono null h to identical hai
            return true;
        }else if(root == NULL || subRoot == NULL){
            //agar dono m se ek bhi NULL hai to compare hi nhi kr skte
            return false;
        }
         //agar curr  root node ki value or subroot ki root node eq h to aage check karenge ki tree identical h kya agr hai to true return kr denge 
         if(root->val == subRoot->val){
              if(isIdentical(root, subRoot)){//isIdentical true return kare to hi true return krna hai agar usne false return kiya hai matlab jis part k liye hmne search kiya hai , vha p subtree nhi h kahi or exist kr skti h to on basis of this we cant return false directly in isSubtree func
                return true;
              }
         }
        // nhi to left wali subtree m subroot dhundhne k liye recursive call
        bool isleftsubtree = isSubtree(root->left, subRoot);
        //or agar left subtree m identical subtree nhi milti hai to hi rightsubtree m dhundhenge or jo bhi answer h  hogi ya nhi hogi vo right subtree decide kregi kyuki usi ko check krna bacha h
        if(!isleftsubtree){
            return isSubtree(root->right, subRoot);
        }
        return true;
    }