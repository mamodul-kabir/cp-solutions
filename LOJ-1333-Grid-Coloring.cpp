/*
    
    Note        :   		 

    Link        :       

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

const ll mod = 1000000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 100005; 

set<pii> rec; 
ll n,m,k,b; 

bool valid(pii x){
	return x.F <= n && !rec.count(x); 
}

ll binex(ll a,ll b){
	ll ans = 1; 
	while(b){
		if(b % 2) ans = (ans * a) % mod; 
		a = (a * a) % mod; 
		b /= 2; 
	}
	return ans; 
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
    int t; cin>>t; 
    for(int T = 1; T <= t; T++){
    	rec.clear(); 
    	cin>>n>>m>>k>>b; 
    	ll av = (n * m) - b, boro = m; 
    	vector<pii> blk; 
    	for(int i = 0; i < b; i++){
    		ll x,y; cin>>x>>y; 
    		if(x == 1) boro -= 1; 
    		rec.insert({x,y}); 
    	}
    	for(pii r: rec){
    		if(valid({r.F+1,r.S})) boro += 1; 
    	}
    	ll soto = av - boro;
    	//cout<<k sp<<boro sp<<soto  el; 
    	ll ans = binex(k,boro); 
    	ans = (ans * binex(k-1,soto)) % mod; 
    	cout<<"Case "<<T<<": "<<ans el;
    }
    return 0;
}
