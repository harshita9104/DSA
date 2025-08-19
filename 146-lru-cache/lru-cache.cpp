class LRUCache {
public:
//vector use nhi kr skte , kyuki vector m erase krne ka operation O(n) leta 
//isliye linked list is best when we need to erase something isme jab bhi hm koi elem ko access krenge usko us jaagah se htake front ya back kahi par lana pdega jisse identify ho paye ki vo recently used h, to erase krne m shift krna nhi pdega ll m O(1) m erase ho jaata 
//ab linked list m bhi elem ko access krne k liye iterate hi krna pdta
//the only way to access a elem in ll in O(1) is using adress 
//to adress ko kahi store kr lenge jisse hme pta chal jaega ki ek particular key wala elem is adress pr stored h
//map will be like this {key, {adress, value}}...kyuki lru cache key value pair store krta
//ab erase kr dia to bhi prev elem k pointer ko next elem par point krane k liye
//prev elem ka access chahiye adress se to sirf us elem ka hi access milta jisko remove krna
//to prev elem ko bhi access krne k liye doubly linked list ka use krenge
//ab adress assign kaise hoga jab bhi hm koi elem daalenge ll m to front se daalenge or usko dll.begin() adress assign kr denge aise har baar jo bhi elem dll m jaega usko ek naya adress assign hoga jisko map m store kr lenge
//jisko abhi abhi access kiya usko front pr rkenge 
//to least recently used back m rhega 
//jab bhi put krne k baad capacity badh jaati h cache ki to last wale elem dll.back() se access krke map se erase krenge or pop_back() kr denge aise sare operation O(1) m ho jaenge
//ek func recently used elem ko front par lane k liye bhi bnega
list<int> dll;
int n;
unordered_map<int,pair<list<int>::iterator, int>> mp;//ll k adress ka data type list<int>::iterator
    LRUCache(int capacity) {
        n = capacity;
    }
    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);//isko erase krdoge to iska prev pointer khud ki next ko point krdega
        dll.push_front(key);
        mp[key].first = dll.begin();//adress update krdo is key ka jisko abhi front m push kia

    }
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;
        else{
        //if already present in map then make it recently used and return its value 
        makeRecentlyUsed(key);
        return mp[key].second;//value return krdo
        }
    }
    
    void put(int key, int value) {
        //agar already present hai to bas is key ki value update hogi
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        }else{
            //present nhi to isko dll m front m daaldo
            // key not present, need to insert
            if(mp.size() == n) {
                // evict least recently used from back
                int lru = dll.back();
                dll.pop_back();
                mp.erase(lru);
            }
            // insert new key at front
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
    }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */