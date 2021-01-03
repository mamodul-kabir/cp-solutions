/*
    
    Note        :               Get a dummy line for input or you will get input in wrong format.    (Check line 108)


    Link        :               https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1742
    
    
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

const ll mamod = 100000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
ll si = 26;

string dum;
ll n,k,cs[5],res[101][5];
vector<pair<pii,int>> ar[101][5]; 
bool prs[101][5];

void fun(string st,ll x){
    vector<ll> tem;
    ll s = 0;
    for(ll i = 0, lm = st.size(); i < lm; i++){
        if(st[i] == ' '){
            ll r; 
            istringstream(string(st.begin() + s,st.begin() + i))>>r;
            tem.pb(r);
            s = i + 1;
        }else if(i == lm - 1){
            ll r;
            istringstream(string(st.begin() + s,st.begin() + i + 1))>>r;
            tem.pb(r);
        }
    }
    for(ll r: tem){
        for(ll i = 0; i < n; i++){
            if(prs[r][i]){
                ar[r][i].pb({{r,x},60});
                ar[r][x].pb({{r,i},60});
                //cout<<r sp<<x sp sp sp<<r sp<< i sp sp sp<<60 el;
            }
        }
    }
    for(ll r: tem) prs[r][x] = 1;
    for(ll i = 1, lm = tem.size(); i < lm; i++){
        ll spnd = (tem[i] - tem[i-1]) * cs[x];
        ar[tem[i]][x].pb({{tem[i-1],x},spnd});
        ar[tem[i-1]][x].pb({{tem[i],x},spnd});
        //cout<<tem[i] sp<<x sp sp sp<<tem[i-1] sp<< x sp sp sp<<spnd el;
    }
    return;
}

void findsol(){
    for(ll i = 0; i < 101; i++) for(int j = 0; j < n; j++) res[i][j] = 2000000000000000000;
    priority_queue<pair<ll,pii>> qq;
    for(int i = 0; i < n; i++){
        if(prs[0][i]){
            res[0][i] = 0;
            qq.push({0,{0,i}});
        }
    }
    while(!qq.empty()){
        auto q = qq.top(); qq.pop();
        for(auto r: ar[q.S.F][q.S.S]){
            if(res[r.F.F][r.F.S] > res[q.S.F][q.S.S] + r.S){
                res[r.F.F][r.F.S] = res[q.S.F][q.S.S] + r.S;
                qq.push({-r.S,r.F});
            }
        }
    }
    ll ans = 2000000000000000000;
    for(ll i = 0; i < n; i++) ans = min(res[k][i],ans);
    ans == 2000000000000000000 ? cout<<"IMPOSSIBLE" el : cout<<ans el;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
    while(cin>>n>>k){
        for(int i = 0; i < 101; i++) for(int j = 0; j < n; j++) ar[i][j].clear();
        memset(prs,false,sizeof(prs));
        for(ll i = 0; i < n; i++) cin>>cs[i];
        getline(cin,dum);                                                           // Get a line input as a dummy, it  is one kind of bug of this problem. 
        for(ll i = 0; i < n; i++){
            string st; 
            getline(cin,st);
            fun(st,i);
        }
        findsol();
    }
    return 0;
}
