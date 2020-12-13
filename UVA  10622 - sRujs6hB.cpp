/*
    
    Note        :  	Observation and corner-case here is : if n is negative then p cant be positive because it will force n to be		
			positive, which is contradictory. 

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
#define pii pair<int,int> 


using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 1000000000;
const ll mxr = 1e6 + 10;

ll binex(ll a,ll b){
	ll ans = 1;
	while(b > 0){
		if(b&1) ans *= a;
		a *= a;
		b >>= 1;
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
    ll n;
    while(cin>>n){
    	if(n == 0) break;
    	bool ng = 0;
    	if(n < 0) n *= -1, ng = 1;
    	ll ans = 1;
    	for(int i = 2; i < 32; i++){
    		ll ai = pow(n,(ld)1/i);
    		ll tem1 = binex(ai,i),tem2 = binex(ai + 1,i);
    		//cout<<ai sp<<tem1 sp<<tem2 sp<<n el;
    		if((tem1 == n || tem2 == n)){
    			if(ng && i % 2 == 0) continue;
    			ans = i;
    		}
    	}
    	cout<<ans el;
    }
    return 0;
}