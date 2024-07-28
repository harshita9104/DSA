    /* Should return minimum distance between a and b
    in a tree with given root*/
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
    int dist(Node* root , int n){
        if(root == NULL){
            return -1;//agar dhundhte hue hm null tak pahuch gye h to aage -1 retur karo
        }
        //agar hm jisse dhoondh rhe vha p hm khade h to dist 0 hoga
        if(root->data == n){
            return 0;
        }
        //agar aisa nhi h to left or rightsubtree m search karo
        int leftdist = dist(root->left, n);
        int rightdist = dist(root->right, n);
        //agar left ya right m se kahi bhi hme n milta hai hai to root node apne upar wale node ko ya sidha hi leftdist +1 ya rightdist+1 larle return krega
        if(leftdist != -1){
            //yani n , root ki left m mil gya hai
            return leftdist +1;//apne parent node ko +1 karke return karo kyuki ab us dist m ek edge add ho gyi h
        }
        //or agar right m n mila h
        //left ya right m se ek hi jagah p milega
        if(rightdist != -1){
            return rightdist +1;
        }
        return -1;// agar kahi nhi mila hai to -1 retur krdo
    }
    int findDist(Node* root, int a, int b) {
        //min dist bw any two nodes will pass thr their lca
        //min dist = lca to a+ lca to b
        Node* lca = lowestCommonAncestor(root, a , b);
        int dist1 = dist(lca, a);
        int dist2 = dist(lca, b);
        return dist1+dist2;
        
    }