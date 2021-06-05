#include <iostream>
#include <cstring>

using namespace std;

/**
 * Design a HashMap without using any built-in hash table libraries.

    Implement the MyHashMap class:

    MyHashMap() initializes the object with an empty map.
        * void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
        * int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
        * void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 */


class MyHashMap {
private:
    const int MAPSIZE = 900000 + 123;
    int *mymap_value;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        mymap_value = new int[MAPSIZE];
        memset(mymap_value, -1, sizeof(int) * MAPSIZE);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        mymap_value[key % MAPSIZE] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return mymap_value[key % MAPSIZE];    
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        mymap_value[key % MAPSIZE] = -1;    
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
int main (int argc, char **argv) {
    return 0;
}