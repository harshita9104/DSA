class LFUCache {
public:
int cap;
int min_freq;
//key->{val, freq}
unordered_map<int, pair<int, int>> key_val_freq;
//freq-> doubly linked list of keys
unordered_map<int, list<int>> freq_list;
//key-> pointer to pos in freq list
unordered_map<int, list<int>::iterator> key_iterator;
    LFUCache(int capacity) {
        cap = capacity;
        min_freq=0;
    }
    
    int get(int key) {
        if(key_val_freq.find(key) == key_val_freq.end()){
            return -1;
        }
        increasefreq(key);
        return key_val_freq[key].first;
    }
    
    void put(int key, int value) {
        if(key_val_freq.find(key) != key_val_freq.end()){
            key_val_freq[key].first = value;
            increasefreq(key);
            return;
        }
        if(key_val_freq.size() >= cap){
            int key_to_evict = freq_list[min_freq].front();
            freq_list[min_freq].pop_front();
            key_val_freq.erase(key_to_evict);

        }
        key_val_freq[key] = {value, 1};
        freq_list[1].push_back(key);
        key_iterator[key] = --freq_list[1].end();
        min_freq = 1;

    }
private:
  void increasefreq(int key){
    int curr_freq = key_val_freq[key].second;
    freq_list[curr_freq].erase(key_iterator[key]);
    if(freq_list[curr_freq].empty()){
        freq_list.erase(curr_freq);
        if(min_freq == curr_freq){
            min_freq++;
        }
    }
    int next_freq = curr_freq +1;
    key_val_freq[key].second = next_freq;
    freq_list[next_freq].push_back(key);
    key_iterator[key] = --freq_list[next_freq].end();
  }

};
// capacity =2, min freq =0;
// put(1,1) key_val {1:{1,1}} , add 1 to freq_list[1], min_freq =1
// put(2,2) key_val{2:{2,1}, 1:{1,1}}
// get(1)


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */