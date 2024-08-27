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
vector<int>v;
vector<vector<int> > adj;
int ans;
void dfs(int curr,int p){
	int mn = 1e11;
	if(adj[curr].size() == 1 && curr != 0) mn = min(mn,v[curr]);
	for(auto x:adj[curr]){
		if(x != p){
			dfs(x,curr);
			mn = min(v[x],mn);
			//cout << curr << " " << x << " " << mn << endl;
		}
	}
	if(curr != 0){
		if(mn <= v[curr]) v[curr] = mn;
		else{
			v[curr] = (v[curr] + mn)/2;
		}
	}
	else{
		v[curr] += mn;
	}
}
int32_t  main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		v.clear();adj.clear();
		v.resize(n,0);
		for(int i = 0;i < n;i++) cin >> v[i];
		adj.resize(n);
		ans = 0;
		for(int i = 1;i < n;i++){
			int x;cin >> x;x--;
			adj[i].push_back(x);
			adj[x].push_back(i);
		}
		dfs(0,-1);
		//for(int i = 0;i < n;i++) cout << v[i] << " ";
		//cout << endl;
		cout << v[0] << endl;
	}
}