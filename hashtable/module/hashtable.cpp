#include "hashtable.hpp" 
using namespace std;


//Class node 
Node :: Node(int key, string value ) {
    _key = key;
    _value = value;
}

//Getter da chave
int Node :: getKey() {
    return _key;
}

//Getter do valor
string Node :: getValue() {
    return _value;
}


//Getter do próximo nodo
Node** Node :: getNextP() {
    return &_next;
}

//exception treatment recursive
void Hashtable ::  _openningAddressing(Node** pointer, int key, string value) {
    if( *pointer ) {
        _openningAddressing((*pointer) -> getNextP(), key, value);
        return; 
    }
    *pointer = new Node(key, value);
}

//print auxiliar 
void Hashtable ::  _printOpenAddress(Node** pointer) {
    if( *pointer ) {
        cout << "key: " << (*pointer) -> getKey() << " | value: " << (*pointer) -> getValue() << "  **open addressing** " << endl;
        _printOpenAddress((*pointer) -> getNextP());
    }
}

//hash function method
int Hashtable :: hashFunction(int key) {
    return key % size + 1;
}

//add node
void Hashtable :: put(int key, string value) {
    //is empty
    if( table[ this -> hashFunction(key)] == NULL )
        table[ this -> hashFunction(key)] = new Node(key, value);

    //exception treatment
    else _openningAddressing(table[this->hashFunction(key)] -> getNextP(), key, value);
}

//show node
void Hashtable :: __print__() {
    cout << "hashtable: " << endl;
    for( int i = 0; i < size; i++ ) {
            if( table[i] != NULL ) {
                cout << "key: " << table[i] -> getKey() <<  " | value: " << table[i] -> getValue() << endl;
                _printOpenAddress(table[i] -> getNextP());
            }
    }
}