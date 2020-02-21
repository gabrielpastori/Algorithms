#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 10010
#define INF 999999999
int distancia[MAXN],processado[MAXN],n;
vector<pair<int,int> > v[MAXN];
void dijkstra(int s){
    for(int i=0;i<n;i++){
        distancia[i]=INF;
        processado[i]=0;
    }
    distancia[s]=0;

    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > fila;
    fila.push(make_pair(0,s));

    while(true){
        int davez=-1;
        
        while(!fila.empty()){
            int atual=fila.top().second;
            fila.pop();
            if(processado[atual]==0){
                davez=atual;
                break;
            }
        }
        if(davez==-1) break;
        processado[davez]=1;

        for(int i=0;i<v[davez].size();i++){
            int atual=v[davez][i].second;
            int dist=v[davez][i].first;

            if(distancia[atual]>(distancia[davez]+dist)){
                distancia[atual]=distancia[davez]+dist;
                fila.push(make_pair(distancia[atual],atual));
            }
        }
    }

}