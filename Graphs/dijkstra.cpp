#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define MAXN 1100 //Valor arbitrário para a quantidade máx. de vértices
#define pii pair<int,int>
int n,m; //Número de vértices e arestas do grafo, respectivamente
int distancia[MAXN],visitado[MAXN];
vector<pii> v[MAXN]; //Defino o vetor que armazenará as arestas
void dijkstra(int s){ //s é o vértice inicial
    for(int i=0;i<=(n+1);i++){
        distancia[i]=INT_MAX; //Atribuo o maior inteiro a todas as distâncias
        visitado[i]=0; //Defino todos os vértices como não visitados
    }
    distancia[s]=0; //Defino como 0 a distância do vértice inicial
    priority_queue<pii,vector<pii>,greater<pii> > fila;
    fila.push(make_pair(distancia[s],s)); //Adiciono na fila que vai ser processado o vértice s e sua distância
    while(true){
        int davez=-1;
        while(!fila.empty()){
            int atual=fila.top().second; //Escolho o primeiro da fila
            fila.pop();
            if(!visitado[atual]){
                davez=atual; //O "davez" a ser processado é o escolhido (o atual)
                break;
            }
        }
        if(davez==-1) break; //Não há mais vértices para serem processados
        visitado[davez]=1; //davez foi visitado

        for(int i=0;i<v[davez].size();i++){ //percorro todos os vizinhos de "davez"
            int atual=v[davez][i].second;
            int dist=v[davez][i].first;
            if(distancia[atual]>(distancia[davez]+dist)){ //Se encontrei um caminho mais curto
                distancia[atual]=distancia[davez]+dist; //Defino a nova distância
                fila.push(make_pair(distancia[atual],atual)); //Coloco esse novo vértice(e sua nova distância) na fila
            }
        }
        
    }


}
int main(){
    cin>>n>>m;
    int a,b; //Defino as variáveis que receberão os vértices que compoẽm as arestas
    int d; //Defino a variável que receberá o tamanho da aresta
    for(int i=0;i<m;i++){
        cin>>a>>b>>d;
        v[a].push_back(make_pair(d,b)); //Crio uma aresta a->b com tamanho d
        v[b].push_back(make_pair(d,a)); //Crio uma aresta b->a com tamanho d

    }    
    dijkstra(0);
    cout<<distancia[n+1]<<endl; //Imprime menor distância do vértice 0 para o vértice n+1
}
