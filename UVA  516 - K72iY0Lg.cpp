/*
    
    Note        :  	

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

const ll mod = 100000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;

vector<ll> pri;
bitset<32770> che;

void sei(){
	pri.pb(2);
	for(int i = 4; i <= 32767; i += 2) che[i] = 1;
	for(int i = 3; i <= 32767; i += 2){
		if(!che[i]){
			pri.pb(i);
			if(i * i <= 32767) for(int j = i + i; j <= 32767; j += i) che[j] = 1;
		}
	}
	return;
}

ll binex(ll a,ll b){
	ll ans = 1;
	while(b > 0){
		if(b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

vector<pii> solve(ll n){
	vector<pii> ans;
	for(int i = 0; pri[i] * pri[i] <= n; i++){
		int cnt = 0;
		while(n % pri[i] == 0){
			n /= pri[i];
			cnt += 1;
		}
		if(cnt){
			ans.pb({pri[i],cnt});
		}
	}
	if(n > 1) ans.pb({n,1});
	reverse(all(ans));
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
    sei();
    string st;
    while(getline(cin,st)){
    	if(st == "0") break;
    	vector<ll> pn,pw;
    	vector<pii> ans;
    	ll num = 1,n = st.size(), s = 0, nc = 0;
    	for(int i = 0; i < n; i++){
    		if(st[i] == ' '){
    			nc++;
    			string tem = string(st.begin() + s,st.begin() + i);
    			int tm;
    			istringstream(tem)>>tm;
    			nc % 2 ? pn.pb(tm) : pw.pb(tm);
    			s = i + 1;
    		}else if(i == n - 1){
    			string tem  = string(st.begin() + s,st.begin() + n);
    			int tm;
    			istringstream(tem)>>tm;
    			pw.pb(tm);
    		}
    	}
    	nc = (nc + 1)/2;
    	for(int i = 0; i < nc; i++) num *= binex(pn[i],pw[i]);
    	//cout<<num el;
    	num -= 1;
    	ans = solve(num);
    	n = ans.size();
    	for(int i = 0; i < n; i++){
    		cout<<ans[i].F sp<<ans[i].S;
    		i == n - 1 ? cout el : cout sp;
    	}
    }
    return 0;
}