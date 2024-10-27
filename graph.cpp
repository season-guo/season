#include<vector>
#include<iostream>
#include<string>
using namespace std;
typedef struct table{
    int status=0;
    dgraph *fastest=NULL;
    int distance=0; 
} table;
class dgraph{
    public:
    string name;
    vector<int> toyoudistance={};
    vector<dgraph*> tome={};
    vector<dgraph*> toyou={};
    vector<string> topsort(vector<string> sortedlist={}){
        if (tome.size()==0){
            if(toyou.size()==0) return sortedlist;
            sortedlist.push_back(name);
            for(int i=0;i<toyou.size();i++){
                if ((toyou[i]->toyou).size()==0&&(toyou[i]->tome).size()==1) sortedlist.push_back(toyou[i]->name);
            }
            for(int i=0;i<toyou.size();i++){
                for(int j=0;j<(toyou[i]->tome).size();j++){
                    if ((toyou[i]->tome)[j]==this) {
                        (toyou[i]->tome).erase((toyou[i]->tome).begin()+j);
                        }
                }};
            return (*toyou[0]).topsort(sortedlist);
        }else{
            return (*tome[0]).topsort(sortedlist);
        }
    };
    int dijkstra(dgraph destination){
        dgraph *now=this;
        table root;
        root.status=0;
        vector<table> vec;
        vec.push_back(root);
        for(int j=0;;j++){
        for(int s=0;s<vec.size();s++){
            if(vec[s].status==j){
                ;
            }
        }
    }
}};
int main(){
    dgraph gxc,lql,tjy,mln,sek;
    gxc.name="season",lql.name="feybur",tjy.name="tj",mln.name="melina",sek.name="sekiro";
    gxc.toyou={&lql,&tjy,&sek,&mln},gxc.tome={},gxc.toyoudistance={};
    lql.toyou={&tjy},lql.tome={&gxc};
    tjy.tome={&gxc,&lql},tjy.toyou={&sek};
    sek.tome={&gxc,&tjy};
    mln.tome={&gxc};
    vector<string> a=lql.topsort();
    for(int i=0;i<a.size();i++) cout<<a[i]<<endl;
    return 0;
}