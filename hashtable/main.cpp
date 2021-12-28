#include "module/hashtable.hpp"
using namespace std; 

int main() {
    Hashtable hashtable;

    hashtable.put(1, "Node1");
    hashtable.put(1, "Node2");
    hashtable.put(1, "Node3");
    hashtable.put(1, "Node4");
    hashtable.put(1, "Node4");

    hashtable.__print__();
    return 0;
}