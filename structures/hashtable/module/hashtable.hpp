#include <iostream>
using namespace std;

class Node {
private: 
    Node* _next; 
    string _value;
    int _key;

public:
    //Constructor method
    Node(int key, string value);

    //Getter key 
    int getKey(); 

    //Getter value
    string getValue();

    //Getter next pointer address
    Node** getNextP(); 
};


class Hashtable {
private: 
    int size = 100;
    Node* table[1000]; 

    //execption treatment recursive 
    void _openningAddressing(Node** pointer, int key, string value);

    //print address open
    void _printOpenAddress(Node** pointer);

public: 

    //hash function method
    int hashFunction(int key); 

    //add node 
    void put(int key, string value);

    void __print__();
};
