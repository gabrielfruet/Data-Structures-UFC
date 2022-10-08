#include <iostream>
#include <functional>
#include <string>

using namespace std;

template<typename K, typename V>
class HashNode{
public:
    K key;   
    V* value;
    HashNode<K,V>* next = nullptr;
    HashNode(K key, V* val): key(key), value(val){
    };
    HashNode(){};
};

template<typename K, typename V>
class HashTable{
public:
    HashNode<K,V>* table; 
    int* insertion_counter;
    int size = 0; 
    int cap;
    int colisions = 0;
    function<int(K)> hash;

    HashTable(function<int(K)> hash,int cap = 20){
        this->cap = cap;
        this->table = new HashNode<K,V>[cap];
        this->hash = hash;
        this->insertion_counter = new int[cap];
        for(int i = 0; i < cap; i++){
            insertion_counter[i] = 0;
        }
    }
    void set(K key, V &val){
        int pos = hash(key) % cap;
        HashNode<K,V>* insertion_list = &table[pos];
        HashNode<K,V>* node = new HashNode<K,V>(key,&val);
        
        if(insertion_counter[pos]){
            colisions++;
        }
        insertion_counter[pos]++;

        node->next = insertion_list->next;;
        insertion_list->next = node;
    }
    V* get(K key){
        int pos = hash(key) % cap;
        HashNode<K,V>* finding_list = &table[pos];

        while(finding_list->next && finding_list->next->key != key){
            finding_list = finding_list->next;
        }

        return finding_list->next->value;
    }

    V* del(K key){
        int pos = hash(key) % cap;
        HashNode<K,V>* removing_list = &table[pos];

        while(removing_list->next && removing_list->next->key != key){
            removing_list = removing_list->next;
        }

        if(!removing_list->next){
            return nullptr;
        }
        insertion_counter[pos] -= 1;
        if(insertion_counter[pos]){
            colisions--; 
        }

        HashNode<K,V>* to_delete = removing_list->prox;
        V* val = to_delete->value;
        removing_list->next = removing_list->next->prox;
        
        delete to_delete;

        return val;
    }
};

int inthash(int k){
    return k;
}
int stringhash(string k){
    return k[0];
}

int main(){
    HashTable<string,int> table(stringhash);
    string h = "Novo";
    int v = 1;
    table.set(h, v);

    return 0;
}
