/*
    
    Note        :       It was a really fun to solve. Good problem. 

    Link        :	https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=977

    Boka hoye gelum...
*/
#include "bits/stdc++.h"

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

const ll mod = 1e9 + 7;
const ll mxr = 1e6 + 10;

bool ar[10001][100];
int num[10000];

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
    while(t--){
        int n,k; cin>>n>>k;
        memset(ar,0,sizeof(ar));
        for(int i  = 0; i < n; i++){
            int x; cin>>x;
            x %= k;
            if(x < 0) x = (x + k);
            num[i] = x;
        }
        ar[0][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < k; j++){
                if(ar[i-1][j]){
                    int nex1 = (j + num[i-1]) % k,nex2 = (j - num[i-1]) % k;
                    if(nex2 < 0) nex2 = (nex2 + k);
                    ar[i][nex1] = 1; ar[i][nex2] = 1;
                }
            }
        }
        ar[n][0] ? cout<<"Divisible" el : cout<<"Not divisible" el;
    }
    return 0;
}