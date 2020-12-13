/*
    
    Note        :   		0/1 Bfs problem. 

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

const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;

int dx[8] = {-1,-1,+0,+1,+1,+1,+0,-1};
int dy[8] = {+0,+1,+1,+1,+0,-1,-1,-1};

char lake[1000][1000];
int n,m,t,ar[1000][1000]; 

bool valid(int x,int y){
	if(x < n && x >= 0 &&  y >= 0 && y < m) return 1;
	return 0;
}

void bfs(int x,int y){
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ar[i][j] = (1<<20);
	deque<pii> dq;
	dq.push_front({x,y});
	ar[x][y] = 0;
	while(!dq.empty()){
		pii cur = dq.front(); dq.pop_front();
		//cout<<cur.F sp<<cur.S el;
		for(int i = 0; i < 8; i++){
			int cos = 0,nx = cur.F + dx[i], ny = cur.S + dy[i];
			if(valid(nx,ny)){
				int dir = (lake[cur.F][cur.S] - '0');
				cos += dir != i;
				if(ar[cur.F][cur.S] + cos < ar[nx][ny]){
					ar[nx][ny] = ar[cur.F][cur.S] + cos;
					//cout<<ar[nx][ny] el;
					if(cos) dq.push_back({nx,ny});
					else dq.push_front({nx,ny});
				} 
			}
		}
	}
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
    cin>>n>>m;
    for(int i = 0; i  < n; i++) for(int j = 0; j < m; j++ ) cin>>lake[i][j];
    cin>>t;
	while(t--){
		int xi,yi,xf,yf; cin>>xi>>yi>>xf>>yf; xi -= 1; yi -= 1; xf -= 1, yf -= 1;
		bfs(xi,yi);
		//for(int i = 0; i  < n; i++,cout el) for(int j = 0; j < m; j++,cout sp ) cout<<ar[i][j];
		cout<<ar[xf][yf] el;
	}
    return 0;
}