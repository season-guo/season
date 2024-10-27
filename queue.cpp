#include<vector>
#include<iostream>
using namespace std;
class my_queue{
    public:
    int capacity;
    int *arr;
    int rear;
    int front;
    int size;
    int init(int cap){
        capacity=cap;
        int a[cap];
        arr=a;
    }
    int empty(){
        return size==0; 
    }
    int size(){
        return size;
    }
    int front(){
        return arr[front];
    }
    int back(){
        return arr[rear];
    }
    void push(int ele){
        rear=(rear+1)%capacity;
        arr[rear]=ele;
    }
    void pop(){
        front=(front+1)%capacity;
    }
};