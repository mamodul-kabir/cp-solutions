#include "traffic.h"
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
const ll oo = 3372036000000000;
const ll si = 1000005;
 
 
vector<int> g[1000001]; 
int *pep; 
ll mn[1000001], val[1000001]; 
 
void dfs(int v,int p = -1){
   val[v] += pep[v]; 
   for(int r: g[v]){
      if(r == p) continue; 
      dfs(r,v); 
      val[v] += val[r]; 
   }
   return; 
}
 
void reroot(int v,int p = -1){
    //cout<<v <<"-->" el; 
    for(int r: g[v]){
      //  cout<<r sp<<val[r] el; 
        mn[v] = max(mn[v], val[r]);
    } //cout el; 
   for(int r: g[v]){
      if(r == p) continue; 
      val[v] -= val[r]; 
      val[r] += val[v];
      reroot(r,v);
      val[r] -= val[v];
      val[v] += val[r]; 
   }
   return; 
}
 
int LocateCentre(int N, int pp[], int S[], int D[]){
   pep = pp;
   for(int i = 0; i < N - 1; i++){
      g[S[i]].pb(D[i]);
      g[D[i]].pb(S[i]); 
   }
   memset(mn,-1,sizeof(mn)); 
   memset(val,0,sizeof(val)); 
   dfs(0); 
   reroot(0); 
   pii ans = {1152921504606846976,-1}; 
   for(int i = 0; i < N; i++) ans = min(ans,{mn[i],i}); 
   return ans.S; 
}
