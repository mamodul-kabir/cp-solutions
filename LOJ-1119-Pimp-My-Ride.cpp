/*
 
    Note        :        Fully OC bitmask dp solution. 

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
const ll si = (1<<14);

int mamo[si],ar[14][14],n;

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
    	cin>>n;
    	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin>>ar[i][j];
    	int lim = (1<<n);
    	for(int i = 0; i < lim; i++) mamo[i] = 2000000000;
    	mamo[0] = 0;
    	for(int m = 0; m < lim; m++){
    		for(int i = 0; i < n; i++) if(!(m & (1<<i))){
    			int pri = ar[i][i] + mamo[m];
    			for(int j = 0; j < n; j++) if(m & (1<<j)) pri += ar[i][j];
    			mamo[m | (1<<i)] = min(pri,mamo[m | (1<<i)]);
    		}
    	}
    	//cout<<lim el;
    	cout<<"Case "<<t<<": "<<mamo[lim - 1] el;
    }
    return 0;
}
