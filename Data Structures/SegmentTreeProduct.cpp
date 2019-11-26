#include <iostream>

using namespace std;

#define MAXN 100100
int tree[4*MAXN],x[MAXN];
int odd(int n){
    if(n<0) return -1;
    if(n==0) return 0;
    return 1;

}
void printTree(){
    for(int i=1;i<=15;i++){
        cout<<i<<" "<<tree[i]<<endl;
    }
}
void build(int l,int r,int node){
    
    if(l==r){ 
        tree[node]=x[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*node);
    build(mid+1,r,2*node+1);
    tree[node]=tree[2*node]*tree[2*node+1];
}
void modify(int node,int l,int r,int idx,int v){
    if(l==r){
        x[l]=v;
        tree[node]=v;
        return;
    }
    
    int mid=(l+r)/2;
    if(idx<=mid and l<=idx){
        modify(2*node,l,mid,idx,v);
    }else{
        modify(2*node+1,mid+1,r,idx,v);
    }

    tree[node]=tree[2*node]*tree[2*node+1];
    

}
int query(int node,int l,int r,int tl,int tr){
    if(tl>r or tr<l) return 1;
    if(tl<=l and r<=tr) return tree[node];
    int mid=(l+r)/2;
    return query(2*node,l,mid,tl,tr)*query(2*node+1,mid+1,r,tl,tr);
}
int main(){
    int n,k,p;
    while(cin>>n>>k){
        for(int i=1;i<=n;i++){
            cin>>p;
            x[i]=odd(p);
        }
        build(1,n,1);
        char c;
        int i,v,j;
        for(int l=0;l<k;l++){
            cin>>c;
            if(c=='C'){
                cin>>i>>v;
                modify(1,1,n,i,odd(v));
            }
            if(c=='P'){
                cin>>i>>j;
                int res=query(1,1,n,i,j);
                if(res==0) cout<<"0";
                if(res<0) cout<<"-";
                if(res>0) cout<<"+";
            }
            
        }
        cout<<endl;
    }


}
