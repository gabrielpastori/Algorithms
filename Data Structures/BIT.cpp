#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 100100
int v[MAXN],bit[MAXN];
int n;
int soma(int x){
    int s=0;
    while(x>0){
        s+=bit[x];
        x-=(x&-x);
    }
    return s;

}
void insere(int x){
    while(x<=n){
        bit[x]++;
        x+=(x&-x);
    }
}
int main(){
    
    while(cin>>n){
        if(n==0) break;
        memset(bit,0,sizeof(bit));
        int maior=0;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            maior=max(maior,v[i]);
        }
        int resp=0;
        for(int i=1;i<=n;i++){
            insere(v[i]);
            resp+=soma(maior)-soma(v[i]);
        }
        if(resp%2==0) cout<<"Carlos"<<endl;
        else{
            cout<<"Marcelo"<<endl;
        }
        
    }
	
}
