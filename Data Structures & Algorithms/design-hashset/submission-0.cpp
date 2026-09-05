#include<bits/stdc++.h>
class MyHashSet {
public:
    vector<int> myhash;
    MyHashSet() {
      myhash.assign(1000005,0); 
    }
    
    void add(int key) {
        myhash[key]=1;
    }
    
    void remove(int key) {
        myhash[key]=0;
    }
    
    bool contains(int key) {
        return myhash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */