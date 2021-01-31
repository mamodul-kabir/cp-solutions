/*
 
    Note        :        I had taken a smol hint a long ago. This is almost OC. this was a real tricky problem. 
 
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
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 100;

ll mamo[20][18][2],n;
vector<int> di;
bool p;

bool ch(ll a){
	int hl = (n + 1)/2;
	ll dum = 0;
	for(int i = 0; i < hl; i++){dum *= 10; dum += di[i];}
	int str = n % 2 ? hl - 2 : hl - 1;
	for(int i = str; i >= 0; i--){dum *= 10; dum += di[i];}
	//cout<<dum el;
	return a >= dum;
}

ll dp(int i,int z,bool f){
	if(z != n && i - z >= (n - z + 1)/2){
		//cout<<"->" sp<<i sp<<z el;
		if(f) return p ? 1 : 0;
		return 1;
	}
	if(i == n) return 1;
	if(mamo[i][z][f] == -1){
		ll ans = 0, l = f ? di[i] : 9;
		for(int r = 0; r <= l; r++){
			int nz = r > 0 ? min(z,i) : z; bool nf = f && di[i] == r;
			ans += dp(i+1,nz,nf);
		}
		mamo[i][z][f] = ans;
		//cout<<i sp<<z sp<<f sp<<ans el;
	}
	return mamo[i][z][f];
}

int do_dp(ll a){
	ll x = a;
	if(x <= 0) return x == 0 ? 1 : 0;
	memset(mamo,-1,sizeof(mamo));
	di.clear();
	while(x){di.pb(x % 10); x /= 10;}
	n = di.size();
	reverse(all(di));
	p = ch(a);
	ll ans = dp(0,n,1);
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
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
    	ll a,b; cin>>a>>b; if(a > b) swap(a,b);
    	ll ans = do_dp(b) - do_dp(a - 1);
    	//cout<<do_dp(b) el;
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
