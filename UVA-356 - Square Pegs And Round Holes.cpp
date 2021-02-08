/*
 
    Note        :        Took hint from editorial. Gotta stop taking hints. 
 
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
#define pii pair<ld,ld>
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 100005;

int n;
ld r;
bool ar[155][155];

ld sq(ld a){
    return a * a;
}

bool dis(int x,int y){
    ld ans = sqrt((ld) sq(n - x) + sq(n - y));
    if(r >= ans) return 1;
    return 0;
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
    bool p = false;
    while(cin>>n){
        if(p) printf("\n");
        p = 1;
        r = ((2 * n) - 1)/(ld) 2;
        memset(ar,0,sizeof(ar));
        int ful = 0, par = 0;
        for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) ar[i][j] = dis(i,j);
        for(int a = 0, b = 1; a < n; a++,b++) for(int c = 0, d = 1; c < n; c++,d++){
            if(ar[a][c] && ar[a][d] && ar[b][c] && ar[b][d]) ful += 1;
            else if(ar[a][c] || ar[a][d] || ar[b][c] || ar[b][d]) par += 1;
        }
        ful *= 4; par *= 4;
        printf("In the case n = %d, %d cells contain segments of the circle.\nThere are %d cells completely contained in the circle.\n", n,par,ful);
    }
    return 0;
}
