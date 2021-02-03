/*
 
    Note        :        cpu time: 67ms
 
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
const ll si = 100005;

int re[si],ar[si],n,p; 

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
    	cin>>n>>p;
    	for(int i = 0; i < n; i++) cin>>ar[i];
    	memset(re,0,sizeof(re));
    	ll ans = 0, tot = 0;
    	for(int i = 0; i < n; i++){
    		tot = (ar[i] + tot) % p;
    		re[tot] += 1;
    		ans += re[tot];
    		if(tot > 0) ans -= 1;
    	}
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
