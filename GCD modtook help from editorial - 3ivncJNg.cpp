/*
   YOU CAN'T TAKE HELP FROM EDITORIAL               .m.
    
	Link: 			https://www.codechef.com/problems/GCDMOD

    Boka hoye gelum...
*/
#include "bits/stdc++.h"
#include "bitset"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define showp(x) <<showpoint<<setprecision(x)<<fixed<<
#define pii pair<ll,ll> 


using namespace std;
using ll = long long;
using ld = long double;
 
const ll md = 1000000007;
const ll mxr = 1e6 + 10;

bool cmp(ll a,ll b){
	return a > b;
}

vector<ll> div(ll n){
	vector<ll> ans;
	for(ll i = 1; i * i <= n; i++){
		if(n % i == 0){
			ans.pb(i);
			if(i != n/i) ans.pb(n/i);
		}
	}
	sort(all(ans), cmp);
	return ans;
}

ll exp(ll a,ll b,ll mod){
	ll ans = 1;
	a %= mod;
	while(b > 0){
		if(b % 2) ans = (ans * a) % mod;
		a *= a;
		a %= mod;
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
    while(t--){
    	ll a,b,n; cin>>a>>b>>n;
    	if(a == b){
    		ll ans = exp(a,n,md); ans = (ans + exp(b,n,md)) % md;
    		cout<<ans el;
    	}else{
    		ll dif = a - b; vector<ll> dd = div(dif);
    		for(ll r: dd){
    			ll aa = exp(a,n,r), ba = exp(b,n,r);
    			if((aa + ba) % r == 0){
    				cout<<r % md el; break;
    			}
    		}
    	}
    }
    return 0;
}