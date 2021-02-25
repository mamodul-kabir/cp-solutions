/*
 
    Note        :         The implementation was really tricky. I first used Kosaraju's Algorithm to mark SCCs. then used floyd's algorithm to mark their paths and to count distinct path. 
 
    Link        :      
 
 
*/
 
 
#include "bits/stdc++.h"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end()
#define pii pair<int,int>
#define vec vector<ll> 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 100000007;
const ll si = 10006;

int wlp[32][32],mx; 
bool tnt[32],ar[32][32],v[32],rv[32][32],res[32][32];
stack<int> tp; 

void pdfs(int i){
    v[i] = 1;
    for(int r = 0; r <= mx; r++){
        if(!v[r] && wlp[i][r]) pdfs(r);
    }
    tp.push(i);
}

void sdfs(int i,bool scc){
    v[i] = 1;
    for(int r = 0; r <= mx; r++){
        if(!v[r] && rv[i][r]){
            scc |= 1;
            sdfs(r,scc);
        }
    }
    tnt[i] = scc;
    return;
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
    int t = 0,e; 
    while(cin>>e){
        mx = -1;
        memset(wlp,0,sizeof(wlp)); memset(rv,0,sizeof(rv)); memset(ar,0,sizeof(ar));
        memset(res,0,sizeof(res));
        for(int i = 0; i < e; i++){
            int a,b; cin>>a>>b; 
            ar[a][b] = 1;
            wlp[a][b] += 1;
            rv[b][a] = 1;
            mx = max(mx,max(a,b));
        }
        memset(tnt,false,sizeof(tnt));
        memset(v,false,sizeof(v));
        for(int i = 0; i <= mx; i++){
            ar[i][i] = 1;
            if(!v[i]) pdfs(i);
        }
        memset(v,false,sizeof(v));
        while(!tp.empty()){
            int x = tp.top(); tp.pop();
            if(!v[x]) sdfs(x,0);
        }
        for(int i = 0; i <= mx; i++) for(int j = 0; j <= mx; j++){
            if((tnt[i] || tnt[j]) && ar[i][j]) res[i][j] = 1;
        }
        for(int k = 0; k <= mx; k++) for(int i = 0; i <= mx; i++) for(int j = 0; j <= mx; j++){
            wlp[i][j] += (wlp[i][k] * wlp[k][j]);
            ar[i][j] |= (ar[i][k] && ar[k][j]);
            res[i][j] |= ((ar[i][k] && ar[k][j]) && (res[i][k] || res[k][j]));
        }
        for(int i = 0; i <= mx; i++) for(int j = 0; j <= mx; j++){
            if((ar[i][j] && (tnt[i] || tnt[j])) || res[i][j]) wlp[i][j] = -1;
        }
        cout<<"matrix for city "<<t++ el;
        for(int i = 0; i <= mx; i++,cout el) for(int j = 0; j <= mx; j++){
            cout<<wlp[i][j];
            if(j < mx) cout sp;
        }
    }
    return 0;
}
