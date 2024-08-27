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
int query(int a,int b){
	cout << "? " << (a + 1) << " " << (b + 1) << endl;
	cout.flush();
	int x;cin >> x;x--;
	return x;
	cout.flush();
}
int32_t  main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		if(n == 2){
			cout << "! 1 2" << endl;
			cout.flush();
		}
		else{
			vector<int>vis(n, 0);
			vector<pair<int,int> >edges;
			vis[0] = 1;
			for(int i = 1;i < n;i++){
				int a = 0,b = i;
				while(!vis[i]){
					int val = query(a,b);
					if(val == a){
						edges.push_back(make_pair(a + 1,b + 1));
						vis[b] = 1;
						b = i;a = 0;
					}
					else if(vis[val]){
						a = val;
					}
					else{
						b = val;
					}
				}
			}
			cout << "! ";
			for(int i = 0;i < edges.size();i++){
				cout << edges[i].first << " " << edges[i].second << " ";
				cout.flush();
			}
			cout.flush();
			cout << endl;
		}
	}
}