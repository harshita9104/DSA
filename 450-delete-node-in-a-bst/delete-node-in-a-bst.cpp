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
//phle us node ko search krio jisko delet krna h jab vo node mil jae tab 3 cases bnte h 
//search rec call krte hue krenge jab root ki val key k eq ho jaegi to root node ko hi delet krna h
//agar vo root node leaf node hai to uski jagah simply null return krdo  uske parent ko null value milegi vo us node ko null manega
//agar ek hi child h root node ka to root node k parent ko root node ka not null wala child subtree return krdo
//agar 2 child h to root ko uska inorder successor replace krega inorder succ root node se immediate greater elem hota
//or immediate greater find krne k liye, right subtree m left most elem ko find krna pdega 

    // inorder successor find krne ka helper
    TreeNode* inorder_succ(TreeNode* root) {
        while(root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        // agar key chota hai, left me jao
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        // agar key bada hai, right me jao
        else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // node mil gaya jisko delete krna hai

            // agar leaf node hai to free krdo
            if(root->left == NULL && root->right == NULL) {
                delete(root);
                return NULL;
            }
            // ek hi child hai (right)
            else if(root->left == NULL) {
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
            // ek hi child hai (left)
            else if(root->right == NULL) {
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            // dono child hai
            else {
                // inorder successor nikalo (right subtree ka leftmost)
                TreeNode* succ = inorder_succ(root->right);
                // root ki value ko successor ki value se replace kro
                root->val = succ->val;
                // ab right subtree me se successor ko delete kro
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;
    }
};