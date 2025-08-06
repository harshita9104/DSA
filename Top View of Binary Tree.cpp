/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note: 

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    map<int,int> mp;//this will store horizontal dist and node val
    //hm level wise traverse kr rhe to ek horizontal distance k corresponding node value store kr lenge map m 
    //bfs m agar koi horz dist phirse aaya jo map m already h to vo node update nhi hoga map m 
    //kyuki top view m to jo phle aa rha vahi dikhega //ek horiz dist par hi jo node baad m aa rha vo phle ki piche chup jaega
    vector<int> topView(Node *root) {
        // code here
       queue<pair<Node*,int>> q;//this will store node and its horizontal dist from origin that is root node
       q.push({root,0});
       while(!q.empty()){
          
           int level = q.size();
           while(level--){
                pair<Node*, int> curr = q.front();
                q.pop();
                int node = curr.first->data;
                if(mp.count(curr.second) == 0){
                     mp[curr.second] = node;
                }
                //ab next level k elem yani front node k left child (parent hd -1) and right child (parent hd +1) q m daaldo
                if(curr.first->left != NULL)q.push({curr.first->left, curr.second-1});
                 if(curr.first->right != NULL)q.push({curr.first->right, curr.second+1});
               
           }
           
       }
        vector<int> ans;
        for(const auto &pair: mp){
            ans.push_back(pair.second);
        }
        
        return ans;
    }
};
