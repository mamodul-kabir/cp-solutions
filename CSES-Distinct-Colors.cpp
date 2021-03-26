/*
    
    Note        :           Hashed the colors in range 1...2*10^5, used dsu on tree to find the distinct colors. 
 
    Link        :           https://cses.fi/problemset/task/1139/
 
    Boka hoye gelum...
*/




#include "bits/stdc++.h"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define pii pair<ll,ll> 
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll ms = 200; 
const ll oo = 3372036000000000;
const ll si = 2000005;

int col[si],dis = 0,sz[si],ans[si],occ[si];
vector<int> g[si];  
bool big[si]; 
unordered_map<int,int> rec; 

void add(int v,int p,int q){
    occ[col[v]] += q; 
    if(occ[col[v]] == 0) dis -= 1; 
    else if(occ[col[v]] == 1 && q == 1) dis += 1; 
    for(int r: g[v]){
        if(!big[r] && r != p) add(r,v,q); 
    }
}

void dfs(int v,int p,bool clear){
    int bc = -1, bz = 0; 
    for(int r: g[v]){
        if(r == p) continue; 
        if(sz[r] > bz){
            bz = sz[r]; 
            bc = r; 
        }
    }
    for(int r: g[v]){
        if(r != bc && r != p) dfs(r,v,1); 
    }
    if(bc != -1){
        dfs(bc,v,0); big[bc] = 1; 
    }
    add(v,p,1); 
    ans[v] = dis; 
    if(bc != -1) big[bc] = 0; 
    if(clear) add(v,p,-1); 
    return; 
}

void dfs(int v,int p){
    sz[v] = 1; 
    for(int r: g[v]){
        if(r == p) continue;  
        dfs(r,v); 
        sz[v] += sz[r]; 
    }
    return; 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
    rec.max_load_factor(0.25); 
    rec.reserve(1<<18); 
    int n,z = 1; scanf("%d",&n);  
    for(int i = 1; i <= n; i++){
        //cin>>col[i]; 
        scanf("%d",&col[i]); 
        if(!rec.count(col[i])) rec[col[i]] = z++; 
        col[i] = rec[col[i]];   
    }
    memset(occ,0,sizeof(occ));
    memset(big,0,sizeof(big));  
    //for(int i = 1; i <= n; i++) cout<<col[i] sp; cout el;
    for(int i = 1; i < n; i++){
        int a,b; scanf("%d%d",&a,&b);  
        g[a].pb(b); 
        g[b].pb(a); 
    }
    dfs(1,0); 
    dfs(1,0,0); 
    for(int i = 1; i <= n; i++){
        printf("%d ",ans[i]); 
    }
    return 0;
}
