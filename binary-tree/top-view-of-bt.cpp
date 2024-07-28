// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     
//    2       3
//   /  \    / 
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {//level order traversal karke har node ka HD wrt line passing thr root, note karna hai
    //Top view se hm ek HD k liye levelwise phle aane wale node ko hi dekh skte
    //isliye map ka use krke HD ko key rakhke map m values daalenge node ki
       queue <pair<Node*, int>> q;//(node pointer,HD)
       map<int,int> m;//(HD, node->data)
       //q m sabse pehle root node ka pair push hoga
       q.push(make_pair(root,0));//ab initially q m level 1 ka node hai
       while(!q.empty()){
           //jo node ka pair queue k front m hai vo hmara currnode hai
           pair<Node*,int> curr = q.front();
           q.pop(); //taaki next iteration m q k front m dusra node ho
           Node* currnode = curr.first;
           int currHD = curr.second;
           //currnode k HD wali value ko map m daalne se phle i will check
           //ki map m same HD wala node phle se to nhi h
           if(m.count(currHD) == 0){
               //it means this currHD is not present in map 
               m[currHD] = currnode->data;//key->currHd , value->node ka data
           }
           //ab level order traversal k acc hm currnode k left or right child ko q m back se push kar denge
           if(currnode->left != NULL){
               q.push(make_pair(currnode->left, currHD-1));//left wala child node wrt root node ki line ek kam hoga
           }
           if(currnode->right != NULL){
               q.push(make_pair(currnode->right, currHD+1));//right wale ka HD+1 hoga
           }
       }
       vector<int> v;
       for(auto it: m){
           v.push_back(it.second);
       }
       return v;
       
    }
};