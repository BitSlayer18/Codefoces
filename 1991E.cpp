#include <bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
#define mod 1000000007
#define mod2 998244353
#define len(x) x.size()
#define min3(a,b,c) min(a, min(b,c))
#define max3(a,b,c) max(a, max(b,c))
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1,i>=a;i--)
#define int  long long
#define endl " \n"
using namespace std;

// Make sure to have 1 as 1ll for more than 32 bits
// Make sure to have seprate variables in nested loops
// Make sure minimum initialisation are large enough
// Make sure to use values before reinitilaising them such as count or sum
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvii;
typedef vector<string> vs;
vector<vector<int> > adj;
vector<int>color;
vector<int>vis;
bool is;
void dfs(int curr){
	for(auto x:adj[curr]){
		if(vis[x] && color[x] == color[curr]){
			cout << curr << endl;
			is = false;
			return;
		}
		else if(vis[x]) continue;
		vis[x] = 1;
		color[x] = 1 - color[curr];
		dfs(x);
	}
}
int32_t  main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;cin >> t;
	while(t--){
		int n,m;cin >> n >> m;
		adj.clear();
		vis.clear();
		color.clear();
		color.resize(n,-1);
		vis.resize(n,0);
		adj.resize(n);
		is = true;
		for(int i = 0;i < m;i++){
			int x,y;cin >> x >> y;
			x--;y--;
			adj[x].push_back(y);adj[y].push_back(x);
		}
		color[0] = 0;
		dfs(0);
		if(is){
			cout << "Bob" << endl;
		}
	}
}