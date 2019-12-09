#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 2100
int peso[MAXN],valor[MAXN], tab[MAXN][MAXN];
int p,n;
int knapsack(int obj,int resto){
    if(tab[obj][resto]>=0) return tab[obj][resto];
    if(obj>=n or resto<0) return tab[obj][resto]=0;
    
    int naocoloca=knapsack(obj+1,resto);
    if(resto>=peso[obj]){
        int coloca=(knapsack(obj+1,resto-peso[obj]))+valor[obj];
        return tab[obj][resto]=max(coloca,naocoloca);
    }
    return tab[obj][resto]=naocoloca;
}
int main(){
    memset(tab,-1,sizeof(tab));
    cin>>p>>n;
    for(int i=0;i<n;i++){
        cin>>peso[i]>>valor[i];
    }
    cout<<knapsack(0,p)<<endl;
}
