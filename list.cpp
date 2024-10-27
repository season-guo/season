#include<iostream>
#include <unordered_map>
using namespace std;
class list{
    public:
        double val;
        list* next=NULL;
};
class colist{
    public:
        double val;
        colist* next=NULL;
        colist* last=NULL;
}; 
class LRUCache{
    public:
        int capacity;
        colist *oldest=NULL;
        unordered_map<int,int> hashmap;
        int length=0;
        void init(int capacity);
        void get(int key);
        void put(int key,int val);
};
void LRUCache::init(int cap){
     capacity=cap;
}   
void LRUCache::get(int key){
    if (hashmap.find(key)!=hashmap.end()) printf("%d\n",hashmap[key]);
    else printf("%d\n",-1);
}
void LRUCache::put(int key,int val){ 
    if (capacity==length){
        hashmap.erase(oldest->val);
        oldest=oldest->next;
        colist*newest=new colist;
        newest->last=oldest->last;
        newest->next=oldest;
        oldest->last->next=newest;
        oldest->last=newest;
        newest->val=val;
    }
    else{
    length+=1;
    if (oldest==NULL){
                 
        oldest=new colist;
        oldest->val=val;
        oldest->next=oldest;
        oldest->last=oldest;
    }else{
    colist*newest=new colist;
    newest->last=oldest->last;
    newest->next=oldest;
    oldest->last->next=newest;
    oldest->last=newest;
    newest->val=val;}}
    hashmap.insert({key,val});
    }
int main(){
    LRUCache test;
    test.init(2);
    test.put(1,1);
    test.put(2,2);
    test.get(1);
    test.put(3,3);
    test.get(2);
    test.put(4,4);
    test.get(1);
    test.get(3);
    test.get(4);
}
