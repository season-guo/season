#include<vector>
#include<iostream>
using namespace std;
class hashtable{
    public:
        vector<vector<int>> vec;
        int length;
        int zeroin=-1;
        void init(int len){
            vec=vector<vector<int>> (len);
            length=len;
            for(int i=0;i<len;i++){
                vector<int> a={0,0};
                vec[i]=a;
            }
        }
        void insert(int yournumber){
            int now=yournumber%length;
            while(vec[now][0]!=yournumber&&vec[now][1]!=0){
                now+=1;
                now%=length;
            }
            vec[now][0]=yournumber;
            vec[now][1]+=1;
        }
        void find(int yournumber){
            int validator=0;
            for(int i=yournumber%length;i<length;i=(i+1)%length){
                if (vec[i][0]==yournumber&&vec[i][1]>0) {printf("1");break;}
                if(validator==1&&i==yournumber%length) {printf("0");break;}
                validator=1;
            }
        }
        void delval(int yournumber){
            int validator=0;
            for(int i=yournumber%length;i<length;i=(i+1)%length){
                if (vec[i][0]==yournumber&&vec[i][1]>0) {
                    vec[i][1]-=1;
                    if (vec[i][1]==0) vec[i][0]=0;
                    break;}
                if(validator==1&&i==yournumber%length) break;
                validator=1;
            }
            }
        void delkey(int key){
            if (vec[key][1]>0) vec[key][1]-=1;
            if (vec[key][1]==0) vec[key][0]=0;
        }
        void change(int key,int val){
            vec[key][1]=1;
            vec[key][0]=val;
            }
        };
