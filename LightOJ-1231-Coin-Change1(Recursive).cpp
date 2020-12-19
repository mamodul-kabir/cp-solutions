/*
    
    Note        :         Iterative One is OC. This one is NOT OC. I saw the solution from a blog. The recursive is pretty to look at. 
                          CPU time      :     0.389ms.

    Link        :         http://lightoj.com/volume_showproblem.php?problem=1231
    
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

const ll mod = 100000007;
const ll oo = 3372036000000000;

pii ar[51];
ll mamo[51][1005],k,n;

ll dp(int i,int sum){
	if(sum == k) return 1;
	if(sum > k || i == n) return 0;
	if(mamo[i][sum] == -1){
		ll ans = 0;
		for(int r = 0,lim = ar[i].S; r <= lim; r++){
			ans = (ans + dp(i+1,sum + (r * ar[i].F))) % mod;
		}
		mamo[i][sum] = ans;
	}
	return mamo[i][sum];
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
    	cin>>n>>k;
    	for(int i = 0; i < n; i++) cin>>ar[i].F;
    	for(int i = 0; i < n; i++) cin>>ar[i].S;
    	memset(mamo,-1,sizeof(mamo));
    	ll ans = dp(0,0);
    	cout<<"Case "<<t<<": "<<ans el;
	}	
    return 0;
}
