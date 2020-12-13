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

ll dp[30005],ar[5] = {1,5,10,25,50};
void ini(){
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j <= 30000; j++){
			if(dp[j] > 0 && j + ar[i] <= 30000) dp[j + ar[i]] += dp[j];
		}
	}
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
    ini();
    int n; 
    while(cin>>n){
    	if(dp[n] > 1) cout<<"There are "<<dp[n]<<" ways to produce "<<n<<" cents change.\n";
    	else cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
    }
    return 0;
}