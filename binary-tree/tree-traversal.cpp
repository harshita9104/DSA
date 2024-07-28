void preorder(TreeNode* root, vector<int> &result){//mistack-passby ref
        if(root == NULL){
            return;       
        }
        result.push_back(root->val);
        preorder(root->left, result);
         preorder(root->right, result);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        //preorder traversal is printed in this order (1)root node ,(2) left subtree (3) right subtree
        //recurively we will call our function passing the pointer of our left subtree and right subtree
        vector<int> result;
        preorder(root, result);
        return result;
    }
void inorder(TreeNode* root, vector<int> &result){
        if(root == NULL){
            return;
        }
       //sequence in inorder is root, left, right
        inorder(root->left, result);
         result.push_back(root->val);
        inorder(root->right, result);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
         inorder(root, result);
        return result;
    }

    class Solution {
public:
        vector<vector<int>> output;//This will store the final result, a vector of vectors where each inner vector represents a level in the tree.

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        //we will use a queue kyuki hm q k front se currnode ko consider kr lenge or pop kra denge or q k back m is currnode k left child or right child ko push kr denge
        queue<TreeNode*> q;
        if(root){
            q.push(root);//level 1 k node ko hmne q m daal diya
        }
        //jab tak q khalli nhi ho jati tab tk level order traversal karte rhenge
        while(!q.empty()){
// Determine the number of nodes at the current level. This is done before the for-loop to ensure the size remains constant even as nodes are added to the queue during the iteration
            int l = q.size();//initially level 1 ki root node h q m
            vector<int> v;//This vector will store the values of the nodes at the current level.
                     for(int i = 0; i< l; i++){
                TreeNode* curr = q.front();//level 1 ka elem q k front p h
                //ab iske child nodes ko q k back se push kardo
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
                v.push_back(curr->val);
                q.pop();//level 1 k elem ko pop kardo
//or kyuki hm har front wale node ko vector m daalne k baad pop karte jaa rhe to for loop ki next itertion m us level ka dusra node ayega q k front m                               
            }//is loop k khatam hone k baad vector v m ek level k nodes hai ab isko hm 2d vector output m daal denge 
        output.push_back(v);
        //hmne q m back se curr node k left or right child node daal diye the , ab queue m next level k nodes hai
        //next time for loop utni baar chlega jitne ek level m nodes honge or kyuki hm har front wale node ko vector m daalne k baad pop karte jaa rhe to for loop ki next iteration m us level ka dusra node aayega q k front m
        }
        return output;
    }
};