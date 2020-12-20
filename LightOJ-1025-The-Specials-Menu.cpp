/*
   
    Note        :            Count all the sub-palindromes in a string,
                             Special case: 
                                if string[start] == string[end], 
                                then string[strt]+string[end] is a palindrome, and all the sub-palindrome in start+1....end-1 is also an additional palindrome,
                                ie. let p is a subpalindrome in string[start+1.....end-1] then string[start] + p + string[end] is also a palindrome.
                                that is why add 1 + dp(start+1,end-1) to the answer.
                                
                              for other cases, with or without the special case, 
                                count the palindromes in string[start+1...end] and string[start...end-1] notice that palindromes in string[start+1...end-1] are being 
                                counted twice, that's why subtract, string[start+1....end-1]
                                
                             CPU Time: 0.004 ms.
 
    Link        :           http://lightoj.com/volume_showproblem.php?problem=1025
   
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

ll mamo[61][61],n;
string a;

ll dp(int i,int j){
	if(i == j) return 1;
	if(i > j) return 0;
	if(mamo[i][j] == -1){
		ll ans = 0;
		if(a[i] == a[j]) ans = 1 + dp(i+1,j-1);
		ans += (dp(i+1,j) + dp(i,j-1)) - dp(i+1,j-1);
		mamo[i][j] = ans;
	}
	return mamo[i][j];
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
    	cin>>a;
    	memset(mamo,-1,sizeof(mamo));
    	n = a.size();
    	ll ans = dp(0,n-1);
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
