/*
 
    Note        :      A really fun problem. 
                       CPU time : 0.019 ms. 

    Link        :      http://lightoj.com/volume_showproblem.php?problem=1110
 
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
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 1000006;

int mamo[103][103],len,na,nb;
string a,b;
string mmo[103][103];


string do_dp(){
	na = a.size();
	nb = b.size();
	memset(mamo,0,sizeof(mamo));
	for(int i = 0; i <= na; i++) for(int j = 0; j <= nb; j++) mmo[i][j] = "";
	for(int i = 1; i <= na; i++){
		for(int j  = 1; j <= nb; j++){
			if(a[i - 1] == b[j - 1]){
				mamo[i][j] = 1 + mamo[i-1][j-1];
				mmo[i][j] = mmo[i - 1][j - 1] + a[i - 1];
			}
			else{
				mamo[i][j] = max(mamo[i-1][j],mamo[i][j-1]);
				if(mamo[i][j-1] == mamo[i-1][j]){
					mmo[i][j] = min(mmo[i][j-1],mmo[i-1][j]);
				}else if(mamo[i][j-1] > mamo[i-1][j]) mmo[i][j] = mmo[i][j-1];
				else mmo[i][j] = mmo[i-1][j];
			}
		}
	}
	len = mamo[na][nb];
	if(len == 0) return ":(";
	return mmo[na][nb];
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
    	cin>>a>>b;
    	string ans = do_dp();
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
