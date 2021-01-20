/*
 
    Note        :                   Had to know about modular inverse. I had problem with the last /2 part. Had to find the mod inverse of 2 and 10^9 + 7. 

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
const ll si = (1<<10);

ll mamo[501][63630],n,hi,inv = 1;

int fb(int i,int a){
	int b = (i * (i-1))/2;
	b -= a;
	return b;
}

void binex(){
	ll a = 2, b = 1000000005;
	while(b){
		if(b&1) inv = (inv * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
}

ll dp(ll i,ll a){
	ll b = fb(i,a);
    if(i == n + 1) return a == b;
    if(a > hi || b > hi) return 0;
    if(mamo[i][a] == -1){
        ll ans;
        ans = (dp(i+1,a + i) + dp(i+1,a))% mod;
        mamo[i][a] = ans;
    }
    return mamo[i][a];
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
    cin>>n;
    memset(mamo,-1,sizeof(mamo));
    hi = (n * (n + 1))/4;
    binex();
    ll ans = dp(1,0);
    ans = (ans * inv) % mod;
    cout<<ans el;
    return 0;
}
