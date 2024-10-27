#include <iostream>
#include <vector>
using namespace std;
class listnode{
    public:
        double val=0.0;
        listnode* next=NULL;
};
class tree{
    public:
       double val=0;
       tree* firstchild=NULL;
       tree* nextsibling=NULL; 
       void repre(tree* yourtree,int depth=0){
        while (yourtree!=NULL){
        for(int i=0;i<depth;i++) printf("    ");
        printf("%.2f\n",yourtree->val);
        repre(yourtree->firstchild,depth+1);
        yourtree=yourtree->nextsibling;}
}
       void reaft(tree* yourtree,int depth=0){
        while (yourtree!=NULL){
        reaft(yourtree->firstchild,depth+1);
        for(int i=0;i<depth;i++) printf("    ");
        printf("%.2f\n",yourtree->val);
        yourtree=yourtree->nextsibling;}
}
        void relay(tree* yourtree,int depth=0,vector<vector<double>>*myvec=new vector<vector<double>> ,int nosibling=-1){
        while (yourtree!=NULL){
        if ((*myvec).size()==depth){
        vector<double> s={};
        (*myvec).push_back(s);
        };
        if (yourtree->nextsibling==NULL) nosibling+=1;
        vector<double> s=(*myvec)[depth];
        s.push_back(yourtree->val);
        (*myvec)[depth]=s;
        if(yourtree->firstchild==NULL&&nosibling==depth){
            for(int i=0;i<(*myvec).size();i++){
                for(int j=0;j<((*myvec)[i]).size();j++){
                    for(int s=0;s<i;s++) printf("    ");
                    printf("%.2f\n",(*myvec)[i][j]);
                }
            }
        }
        relay(yourtree->firstchild,depth+1,myvec,nosibling);
        yourtree=yourtree->nextsibling;}
        
} 
        void pre(tree* yourtree,int depth=0){
            std::vector<tree*> vec;
            do{
                for(int i=0;i<depth;i++) printf("    ");
                printf("%.2f\n",yourtree->val);
                if (vec.size()==depth) vec.push_back(yourtree);
                if(yourtree->firstchild!=NULL){
                vec[depth]=yourtree;
                yourtree=yourtree->firstchild;
                depth+=1;}
                else if (yourtree->nextsibling!=NULL) yourtree=yourtree->nextsibling;
                else{
                     yourtree=vec[depth-1]->nextsibling;
                     depth-=1;
                }
            }while(depth>0);
};
        void lay(tree* yourtree,int depth=0){
            vector<tree*> vec;
            vector<vector<double>>myvec={};
            int nosibling=-1;
            do{ if (yourtree->nextsibling==NULL) nosibling+=1;
                if (vec.size()==depth) vec.push_back(yourtree);
                if (myvec.size()==depth){
                vector<double> s={};
                myvec.push_back(s);
            };  
                vector<double> s=myvec[depth];
                s.push_back(yourtree->val);
                myvec[depth]=s;
                if(nosibling==depth&&yourtree->firstchild==NULL) break;
                if(yourtree->firstchild!=NULL){
                vec[depth]=yourtree;
                yourtree=yourtree->firstchild;
                depth+=1;}
                else if (yourtree->nextsibling!=NULL) yourtree=yourtree->nextsibling;
                else{
                     yourtree=vec[depth-1]->nextsibling;
                     depth-=1;
                     nosibling-=1;
                }
            }while(depth>0);
            for(int i=0;i<myvec.size();i++){
                for(int j=0;j<myvec[i].size();j++){
                    for(int s=0;s<i;s++) printf("    ");
                    printf("%.2f\n",myvec[i][j]);
                }
            }
        };
        void aft(tree* yourtree,int depth=0){
            vector<tree*> vec;
            do{ if(yourtree==NULL){
                for(int i=0;i<depth-1;i++) printf("    ");
                    printf("%.2f\n",vec[depth-1]->val);
                    yourtree=vec[depth-1]->nextsibling;
                    depth-=1;
                    continue;
            }
                if (vec.size()==depth) vec.push_back(yourtree);
                if(yourtree->firstchild!=NULL){
                vec[depth]=yourtree;
                yourtree=yourtree->firstchild;
                depth+=1;}
                else if (yourtree->nextsibling!=NULL){
                    for(int i=0;i<depth;i++) printf("    ");
                    printf("%.2f\n",yourtree->val);
                    yourtree=yourtree->nextsibling;}
                else{
                    for(int i=0;i<depth;i++) printf("    ");
                    printf("%.2f\n",yourtree->val);
                    for(int i=0;i<depth-1;i++) printf("    ");
                    printf("%.2f\n",vec[depth-1]->val);
                    yourtree=vec[depth-1]->nextsibling;
                    depth-=1;
                }
            }while(depth>0);
        };
};
int main(){
    tree tree1,tree2,tree3,tree4,tree5,tree6,tree7,tree8,tree9,tree10,tree11;
    tree1.firstchild=&tree2,tree2.nextsibling=&tree3,tree3.nextsibling=&tree4,tree2.firstchild=&tree5,tree5.nextsibling=&tree6,tree6.nextsibling=&tree7,tree3.firstchild=&tree8,tree4.firstchild=&tree9,tree9.firstchild=&tree10,tree10.firstchild=&tree11;
    tree1.val=1.0,tree2.val=2.0,tree3.val=3.0,tree4.val=4.0,tree5.val=5.0,tree6.val=6.0,tree7.val=7.0,tree8.val=8.0,tree9.val=9.0,tree10.val=10.0,tree11.val=11.0;
    tree1.lay(&tree1);
    return 0;
}