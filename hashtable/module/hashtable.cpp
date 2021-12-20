#include <iostream> 
using namespace std;


//Class node 
class Node {
private: 
    int _key;
    string _value;
    Node* next;

public: 
    Node(int key, string value ) {
        _key = key;
        _value = value;
    }

    int getKey() {
        return _key;
    }

    string getValue() {
        return _value;
    }

    Node* getNext() {
        return this -> next;
    }

    void setNext(Node* node) {
        this -> next = node;
    }
};


//class hashtable
class Hashtable {
private:
    int size = 100;
    Node* table[1000];


    //exception treatment
    void openningAddressing(Node* pointer, int key, string value) {
        while( pointer ) {
            pointer = pointer -> getNext();
        }

        pointer = new Node(key, value);
    }

    void printOpenAddress(Node* pointer) {
        while( pointer ) {
            cout << "key: " << pointer -> getKey() << " | value: " << pointer -> getValue() << endl;
            pointer = pointer -> getNext();
            return; 
        }

        printf("entrei nessa treta!");
    }
 
public:
    //hash function method
    int hashFunction(int key) {
        return key % size + 1;
    }

    //add node
    void put(int key, string value) {

        //is empty
        if( table[ this -> hashFunction(key)] == NULL )
            this -> table[ this -> hashFunction(key)] = new Node(key, value);

        //exception treatment
        //else openningAddressing(table[this->hashFunction(key)]->getNext(), key, value);

        else table[this->hashFunction(key)]->setNext(new Node(key, value));
    }

    //show node
    void __print__() {
        cout << "hashtable: " << endl;
        for( int i = 0; i < size; i++ ) {
                if( this -> table[i] != NULL ) {
                    cout << "key: " << table[i] -> getKey() <<  " | value: " << table[i] -> getValue() << endl;
                    printOpenAddress(table[i] -> getNext());
                }
        }
    }

};

int main() {
    Hashtable hashtable;

    hashtable.put(0, "Pedro");
    hashtable.put(0, "Pedro2");

    hashtable.__print__();

    return 0;
}