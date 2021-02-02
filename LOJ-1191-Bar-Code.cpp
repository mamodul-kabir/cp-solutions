/*
 
    Note        :        Non-OC solution, my OC one got TLE. (https://pastebin.com/aHphc7R8)
                         *FOR  there were three dimensions, 1st one stored index, 2nd one stored no. of bars, 3rd one stored no. of consecutive bits. 
                         
                         This solution has two dimensions, 1st one index, 2nd one stored no. of bars.
                         In this problem, for each index, we iterated from 1 to m, if i + iter was valid(<= n), we added the ~char in the next position and this incremented the
                         number of bars by one. 
 
    Link        :      
 
    Boka hoye gelum...
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
 
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

ll n,k,m,mamo[51][51];

ll dp(int i,int b){
	if(i == n) return b == k;
	if(b > k) return 0;
	if(mamo[i][b] == -1){
		ll ans = 0;
		for(int r = 1; r <= m && i + r <= n; r++){
			ans += dp(i+r,b+1);                           // added the inverse character in i+r position. This increased the number of bars by one.
		}
		mamo[i][b] = ans; 
		//cout<<i sp<<b sp<<c sp<<ans el;
	}
	return mamo[i][b];
}

ll do_dp(){
	memset(mamo,-1,sizeof(mamo));
	return dp(0,0);
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
    	cin>>n>>k>>m;
    	ll ans = do_dp();
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
