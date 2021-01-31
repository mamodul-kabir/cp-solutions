/*
 
    Note        :        bitmask dp problem. 2^n * n^2 complexity. 
                         cpu time: 161ms. 
 
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
const ll si = 1<<15;

int ar[15],mamo[si],mx[15][15];


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
    	int n; cin>>n; 
    	for(int i = 0; i < n; i++) cin>>ar[i];
    	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){char r; cin>>r; mx[i][j] = r - '0';}
    	int lim = 1<<n;
    	memset(mamo,0,sizeof(mamo));
    	for(int i = 0; i < lim; i++) for(int r = 0; r < n; r++) if((i & (1<<r))) mamo[i] += ar[r];
    	for(int m = 0; m < lim; m++){
    		for(int i = 0; i < n; i++) if(m & (1<<i)){
    			for(int j = 0; j < n; j++) if(!(m & (1<<j))){
    				int cos = mx[i][j] == 0 ? 20000000 : ceil((ld) ar[j] / mx[i][j]);
    				mamo[m | (1<<j)] = min(mamo[m | (1<<j)],mamo[m] + cos);
    			}
    		}
    	}
    	ll ans = mamo[lim - 1];
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
