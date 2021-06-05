#include <iostream>
#include <cstring> // memset()
using namespace std;



/* Design a HashSet without using any built-in hash table libraries.

    Implement MyHashSet class:

        + void add(key) Inserts the value key into the HashSet.
        + bool contains(key) Returns whether the value key exists in the HashSet or not.
        + void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 */

class MyHashSet {
private:
    const int SETSIZE = 1000000+123;
    bool *myset;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
       myset = new bool[SETSIZE];
       memset(myset, false, sizeof(bool) * SETSIZE);
    }
    ~MyHashSet() {
        // free(myset);
        delete myset;
    }
    void add(int key) {
        myset[key%SETSIZE] = true;
    }
    
    void remove(int key) {
        myset[key%SETSIZE] = false;    
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return myset[key%SETSIZE];    
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */

int main(int argc, char **argv) {

    MyHashSet myset;
    return 0;
}