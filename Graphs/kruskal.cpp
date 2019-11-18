#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 110
struct Aresta{
    int x,y,dist;
};
int pai[MAXN];
bool sorteia(Aresta a, Aresta b){
    return a.dist<b.dist;
}
int find(int x){
    if(pai[x]==x) return x;
    return pai[x]=find(pai[x]);
}
int join(int x,int y){
    x=find(x);
    y=find(y);

    pai[x]=y;
}
int main(){
    Aresta aresta[MAXN];
    int n,f,r;
    cin>>n>>f>>r;
    for(int i=1;i<=n;i++){
        pai[i]=i;
    }
    int a,b,c;
    for(int i=0;i<f;i++){
        cin>>a>>b>>c;
        aresta[i].x=a;
        aresta[i].y=b;
        aresta[i].dist=c;

    }
    sort(aresta,aresta+f,sorteia);
    int cont=0;
    for(int i=0;i<f;i++){
        if(find(aresta[i].x)!=find(aresta[i].y)){
            join(aresta[i].x,aresta[i].y);
            cont+=aresta[i].dist;
        }
    }
    for(int i=0;i<r;i++){
        cin>>a>>b>>c;
        aresta[i].x=a;
        aresta[i].y=b;
        aresta[i].dist=c;

    }
    sort(aresta,aresta+r,sorteia);

    for(int i=0;i<r;i++){
        if(find(aresta[i].x)!=find(aresta[i].y)){
            join(aresta[i].x,aresta[i].y);
            cont+=aresta[i].dist;
        }
    }
    cout<<cont<<endl;
    
    
}
