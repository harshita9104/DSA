class RandomizedSet {
public:
vector<int> vec;
unordered_map<int, int> mp;
    RandomizedSet() {
       
    }
     //map m mila to hi remove kr paenge 
            //index ko access kro map se , ab is val ko O(1) m remove krne k liye is elem ko vec k end m hona pdega
            //is elem ka index pta h last elem ka bhi dono ko swap krdo phir last wala pop krke us val ko map se erase krdo
            //phle chcek krlo jisko remove krna h vo last lem to nhi , agar hai to remove krne ki jarurat nhi
    bool insert(int val) {
        // if val not present, insert & return true
        if(mp.find(val) == mp.end()){
            vec.push_back(val);
            mp[val] = vec.size()-1; // save its index
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        // only remove if present
        if(mp.find(val) != mp.end()){
            int index = mp[val];
            int lastElem = vec.back();
            // swap val with last element
            vec[index] = lastElem;
            mp[lastElem] = index; // update index of lastElem
            // remove last element
            vec.pop_back();
            mp.erase(val); // erase val from map
            return true;
        }
        return false;
    }
    
    int getRandom() {
        //rand() % vec.size(); karne se koi ek index randomly return hota h ...0 to ve.size() -1 m se kuch bhi return hoga us index ka elem return krdo
        int n = vec.size();
        int ind = rand()%n;
        return vec[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */