/*
 
    Note        :        Binary search(optional) + non-classical dp. 
                         had to observe the number system. for each number with 1 one and i zeros, the process for 1 to last element of i - 2 repeats. i - 2 because two 1s cant be adjacent. 
                         so the total number included in the number system with 1 one and i zeros is:
                                  ar[i] = 
                                            ar[i-1]   (for all the previous numbers)  + 
                                                                                          ar[i-2] (for the new included numbers)
                                                                                                                                + 1 (for the number with 1 one and i zeros) 
                                                                                                                                
                         example: for 1 to 12,
                                          1
                                          10
                                          100      1 to the last element of i - 2
                                          101      
                                          
                                          1000
                                          1001      i - 1
                                          1010
                                          
                                          10000    1 one and i zeros.
                                          10001
                                          10010    i 
                                          10100
                                          10101
                                          
 
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
const ll si = 100005;

ll ar[50];

void ini(){
	ar[0] = 0; ar[1] = 1;
	for(int i = 2; i <= 43 && ar[i-1] <= 1000000000; i++) ar[i] = ar[i-2] + 1 + ar[i-1];
	for(int i = 0; i <= 43; i++) ar[i] += 1;
	return;
}

int f(int x){
	int l = 0,r = 43,ans = 0;
	while(l <= r){
		int mid = l + (r -l)/2;
		if(ar[mid] <= x) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

string fun(int n){
	vector<int> v; 
	int mx = -1;
	while(n){
		int ind = f(n);
		n -= ar[ind];
		v.pb(ind);
		mx = max(mx,ind);
	}
	string ans(mx+1,'0');
	for(int r: v) ans[r] = '1';
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
    int T; cin>>T;
    ini();
    for(int t = 1; t <= T; t++){
    	int n; cin>>n; 
    	string ans = fun(n);
    	cout<<"Case "<<t<<": " <<ans el;
    }
    return 0;
}
