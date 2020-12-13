/*
    
    Note        :   		1/x + 1/y = 1/n
				x,y > n so we make x = n+a, y = n + b
				1/(n+a) + 1/(n+b) = 1/n
				(n+a+n+b)/(n+a)(n+b) = 1/n
				n(n+a+n+b) = (n+a)(n+b)
				n^2 + na + n^2 + nb = n^2 + nb + na + ab
				n^2 = ab
				so find all a,b such that n^2 = a*b

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
    	ll ns = n * n;
    	vector<pii> ans;
    	for(int i = 1; i * i <= ns; i++){
    		if(!(ns % i)) ans.pb({(ns/i) + n,i + n});
    	}
    	sort(all(ans),com);
    	cout<<ans.size() el;
    	for(pii r: ans) cout<<"1/"<<n sp<<"= 1/"<<r.F sp<<"+ 1/"<<r.S el;
    }
    return 0;
}