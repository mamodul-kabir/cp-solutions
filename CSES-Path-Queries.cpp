/*
 
    Note        :         Euler Tour + BIT.  

    Link        :      
 
 
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
 
const ll mod = 100000007;
const ll si = 200006;

ll val[si], flat[si * 2],tin[si],tout[si],tim = 1,lim;
vector<int> ar[si];

void upd(ll v,ll x){
	while(v <= lim){
		flat[v] += x;
		v += v & (-v);
	}
	return;
}

ll get(int a){
	ll ans = 0;
	while(a){
		ans += flat[a];
		a -= a & (-a);
	}
	return ans;
}

void dfs(int v,int p){
	tin[v] = tim++;
	upd(tin[v],val[v]);
	for(int r: ar[v]){
		if(r != p) dfs(r,v);
	}
	tout[v] = tim++;
	upd(tout[v],-val[v]);
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
    int n,q; cin>>n>>q;  lim = (2 * n);
    memset(flat,0,sizeof(flat));
    for(int i = 1; i <= n; i++) cin>>val[i];
    for(int i = 1; i < n; i++){
    	int a,b; cin>>a>>b; 
    	ar[a].pb(b); ar[b].pb(a);
    }
    dfs(1,0);
    while(q--){
    	int t; cin>>t; 
    	if(t == 1){
    		int s,x; cin>>s>>x;
    		upd(tin[s],-val[s]),upd(tout[s],val[s]);
    		val[s] = x;
    		upd(tin[s],x); upd(tout[s],-x);
    	}else{
    		int s; cin>>s; 
    		cout<<get(tin[s]) el;
    	}
    }
    return 0;
}
