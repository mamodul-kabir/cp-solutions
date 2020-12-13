/*
    
    Note        :   	This is the TLE submission. 

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

const ll mod = 100000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;

ll lcm(ll a,ll b){
    return ((a * b)/__gcd(a,b));
}

bool com(pii a,pii b){
	return a.F > b.F;
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
    	vector<pii> ans;
    	for(ll i = 2; i <= n + 1; i++){
    		ll num = n * i,lim = ((i+1)/2) + !(i % 2);
    		for(ll r = 1; r < lim; r++){
    			ll th = i - r;
    			if(!(num % r) && !(num % th) && lcm(num/r,num/th) == num) ans.pb({num/r,num/th});
    		}
    	}
    	sort(all(ans),com);
    	cout<<ans.size() el;
    	for(pii r: ans){
    		cout<<"1/"<<n sp<<"= 1/"<<r.F sp<<"+ 1/"<<r.S el;
    	}
    }
    return 0;
}