#include <iostream>

using namespace std;
#define lli long long int
#define MAXN 100100
lli n,v[MAXN],aux[MAXN];
lli merge(int ini,int fim){
    if(ini==fim) return 0;
    int meio=(ini+fim)/2;
    lli resp=merge(ini,meio)+merge(meio+1,fim);
    
    int j=meio+1,tam=0;
    for(int i=ini;i<=meio;i++){
        while(v[i]>v[j] and j<=fim){
            aux[tam]=v[j];
            resp+=(meio-i)+1;
            tam++;
            j++;

        }
        aux[tam]=v[i];
        tam++;
    }
    while(j<=fim){
        aux[tam]=v[j];
        tam++;
        j++;
    }
    for(int i=ini;i<=fim;i++){
        v[i]=aux[i-ini];
    }
    return resp;

}
int main(){
    lli x,y;
    lli resp;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        resp=x*x+y*y;
        v[i]=resp;
        //cin>>v[i];
    }
    cout<<(n*(n-1)/2)-merge(1,n)<<endl;
   
}
