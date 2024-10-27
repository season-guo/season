#include<iostream>
#include<vector>
using namespace std;
/*以后序为例*/
class binarytree{
    public:
    char val;
    binarytree* left=NULL;
    binarytree* right=NULL;
    int sum(){
        int a,b;
        if(right!=NULL){
        b=(*right).sum();
        a=(*left).sum();}
        if (val>='0'&&val<='9') return val-'0';
        if (val=='+') return a+b;
        if (val=='*') return a*b;    
        if (val=='-') return a-b;
        if (val=='/') return a/b;
        }
    };
binarytree* creat(char str[]){
    vector<binarytree*> vec;
    int len=0;
    int size=0;
    while(str[len]!='\0'){
        len+=1;
    }
    int now=0;
    while(now<len){
        if(str[now]>='0'&&str[now]<='9'){
            binarytree *temp=new binarytree;
            temp->val=str[now];
            size+=1;
            now++;
            vec.push_back(temp);
        }
        else{
            binarytree *temp=new binarytree;
            temp->val=str[now];
            temp->left=vec[size-2];
            temp->right=vec[size-1];
            vec.pop_back();
            size-=1;
            vec[size-1]=temp;            
            now++;
        }
        }
    return vec[0];
    }

int compute(char str[]){
    binarytree *computetree=creat(str);
    return (*computetree).sum();
}
int main(){
    char str[]="34+567+**";
    printf("%d",compute(str));
    return 0;
}