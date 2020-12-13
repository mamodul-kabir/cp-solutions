/*
   YOU CAN'T TAKE HELP FROM EDITORIAL               .m.
    
    Note        :       

    Link        :		https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=6100

    Boka hoye gelum...
*/
#include "bits/stdc++.h"
#include "bitset"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define showp(x) <<showpoint<<setprecision(x)<<fixed<<
#define pii pair<int,int> 


using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;

map<char,char> eq = {{'<','>'},{'(',')'},{'{','}'},{'[',']'}};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
    int t; cin>>t;
   	for(int i = 1; i <= t; i++){
    	string st; cin>>st;
    	int n = st.size(),gon = 0, ar[n];
    	memset(ar,0,sizeof(ar));
    	stack<char> bra;
    	vector<int> ans;
    	for(int i = n - 1; i >= 0; i--){
    		char tem = st[i];
    		if(eq.count(tem)){
    			if(bra.empty()) gon = 0;
    			else{
    				char nw = bra.top(); bra.pop();
    				if(eq[tem] != nw) gon = 0;
    				else gon += 2;
    			}
    			ans.pb(gon);
    		}else{
    			bra.push(tem);
    			ans.pb(0);
    		}
    	}
    	reverse(all(ans));
    	cout<<"Case "<<i<<": " el;
    	for(int r: ans) cout<<r el;
    }
    return 0;
}