/*
 
    Note        :        Had to take the hint that x doesnt matter. I oversaw that. 
 
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
const ll si = (1<<16);
bool cmp(int a,int b){return a > b;}
int n,mamo[101][101],k,w;
vector<int> ar;

int dp(int i,int a){
	if(i >= n || a >= k) return 0;
	if(mamo[i][a] == -1){
		int ans = 0,itk = 1,r;
		for(r = i + 1; r < n; r++){
			if(ar[i] - w <= ar[r]) itk += 1;
			else break;
		}
		//cout<<itk sp<<i sp<<a el;
		ans = max(itk + dp(r,a+1),dp(i+1,a));
		mamo[i][a] = ans;
	}
	return mamo[i][a];
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
    	cin>>n>>w>>k; int dum,num;
    	ar.clear();
    	for(int i = 0; i < n; i++){
    		cin>>dum>>num;
    		ar.pb(num);
    	}
    	//ar.pb(-2000000000);
    	sort(all(ar),cmp);
    	//for(int i = 0; i < n; i++) cout<<ar[i] sp; cout el;
    	memset(mamo,-1,sizeof(mamo));
    	int ans = dp(0,0);
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
