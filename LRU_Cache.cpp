class LRUCache{
public:
    list<int> cache_list;
    unordered_map<int, int> cache_hash;
    unordered_map<int, list<int>::iterator> cache_index_hash;
    int capacity_;
    
    LRUCache(int capacity) {
       capacity_  = capacity;
    }
    
    int get(int key) {
        if( cache_hash.count(key) > 0 )
        {
            list<int>::iterator it = cache_index_hash[key];
 
            cache_list.erase(it);
        
            cache_list.push_front(key);
            cache_index_hash[key] = cache_list.begin();   
            
            return cache_hash[key];
        }
        else
            return -1;
    }
    
    void set(int key, int value) {
        if( cache_hash.count(key) == 0 )
        {
            cache_hash[key] = value;
            
            if( cache_list.size() < capacity_)
            {
                cache_list.push_front(key);
                cache_index_hash[key] = cache_list.begin();
            }
            else
            {
                int del_key = *(cache_list.rbegin());
                cache_list.pop_back();
                cache_hash.erase(del_key);
                cache_index_hash.erase(del_key);
                
                cache_list.push_front(key);
                cache_index_hash[key] = cache_list.begin();
                
            }
        }
        else
        {
            cache_hash[key] = value;
            list<int>::iterator it = cache_index_hash[key];
 
            cache_list.erase(it);
        
            cache_list.push_front(key);
            cache_index_hash[key] = cache_list.begin();
        }
        
    }
};