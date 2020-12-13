/*
    
    Note        :  	I already had seen the video. Still had some problem implementing the solution. Need more practice. 
			See the code with note to have a better understanding. 

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

ll dp[51][51], ar[51],l,n;

int rec(int i,int j,int s,int e){
    if(i > j) return 0; 	// if current range is invalid return 0;
    ll dis = e - s;
    if(i == j){			// if only one possible cut is available in this range cut it. But there can be two scenario :
        if(ar[i] == s || ar[i] == e) return 0;  // i. 	If the cut is in the corner of the stick then we dont actually need a cut. 
        else return dis;			//ii. 	If it is not in corner, then we have to take the total size of the stick. 
    }
    if(dp[i][j] != -1) return dp[i][j];		//common dp condition. 
    ll ans = -1;
    for(int x = i; x <= j; x++){		//check  for every possible cut index and take THE MINIMUM. 	 
        if(ans == -1) ans = rec(i,x-1,s,ar[x]) + rec(x+1,j,ar[x],e) + (ar[i] != s && ar[x] != e ? dis : 0); 	// same as the two scenarios. IF in corner take 0, else take the total size
	/*
		Another thing to consider, if cut is taken then the the range is split into two cut ranges.
		ie. start_indx to current_cut_indx - 1 and current_cut_indx + 1 to finish_indx
		And the possible length is also divided into two parts. 
		ie. start_pos to cut_pos and cut_pos to finish_pos
		Example 	: 
				
				-----.-----
				0    5    10    
				for cut in pos 5 (not index) length becomes
				----- -----
				0    5    10  
	*/
        else ans = min(ans,rec(i,x-1,s,ar[x]) + rec(x+1,j,ar[x],e) + (ar[i] != s && ar[x] != e ? dis : 0));
    }
    //cout<<i sp<< j sp<< ans el;
    return dp[i][j] = ans;
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
    while(1){
        cin>>l;
        if(l == 0) break;
        cin>>n; memset(dp,-1,sizeof(dp));
        for(int i = 0; i < n; i++) cin>>ar[i];
        cout<<"The minimum cutting is "<<rec(0,n-1,0,l)<<"." el;
    }
    return 0;
}