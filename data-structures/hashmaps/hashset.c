#include <stdbool.h>
#include <stdlib.h>


typedef struct {
    size_t size;
    size_t capacity;
    int* values;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet* hashSet = (MyHashSet*)malloc(sizeof(MyHashSet));
    hashSet->size = 0;
    hashSet->capacity = 8;
    hashSet->values = (int*)malloc(sizeof(int) * hashSet->capacity);
    return hashSet;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if(obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->values = (int*)realloc(obj->values, sizeof(int) * obj->capacity);
    }
    if (myHashSetContains(obj, key)) return;
    obj->values[obj->size++] = key;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    for(int i = 0; i < obj->size; i++){
        if(obj->values[i]==key){
            obj->values[i] = obj->values[obj->size-1];
            obj->size--;
        }
    }
}

int myHashSetContains(MyHashSet* obj, int key) {
    for(int i = 0; i< obj->size; i++){
        if(obj->values[i] == key) return 1;
    }
    return 0;
    
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/