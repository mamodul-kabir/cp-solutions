/*
    
    Note        :               Easy and OC, but still added it.

    Link        :               http://lightoj.com/volume_showproblem.php?problem=1047
    
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

const ll mod = 100000000;
const ll oo = 3372036000000000;

int ar[32][3],n,mamo[32][3];

int dp(int i,int c){
	if(mamo[i][c] == -1){
		int ans;
		if(i == n) ans = 0;
		else{
			if(c == 1) ans = min(dp(i+1,0),dp(i+1,2)) + ar[i][c];
			else if(c == 2) ans = min(dp(i+1,0),dp(i+1,1)) + ar[i][c];
			else ans = min(dp(i+1,1),dp(i+1,2)) + ar[i][c];
		}
		mamo[i][c] = ans;
	}
	return mamo[i][c];
}

int do_dp(){
	memset(mamo,-1,sizeof(mamo));
	int ans = min(dp(0,0),min(dp(0,1),dp(0,2)));
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
    	cin>>n;
    	for(int i = 0; i < n; i++) cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
    	int ans = do_dp();
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
