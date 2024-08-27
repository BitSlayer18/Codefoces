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
bool is(string a,string b){
	if(a == b) return false;
	if(a[0] == b[0] || a[0] == b[1] || a[1] == b[0] || a[1] == b[1]) return true;
	else return false;
}
int32_t  main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;cin >> t;
	while(t--){
		int n,q ;cin >> n >> q;
		vector<string>v(n);
		for(int i = 0;i < n;i++) cin >> v[i];
		vector<int>left(n),right(n);
		left[0] = -1;
		for(int i = 1;i < n;i++){
			if(!is(v[i],v[i - 1])) left[i] = left[i - 1];
			else left[i] = i - 1;
		}
		right[n - 1] = -1;
		for(int i = n - 2;i >= 0;i--){
			if(!is(v[i],v[i + 1])) right[i] = right[i + 1];
			else right[i] = i + 1;
		}
		/*for(int x : left) cout << x << " ";
		cout << endl;
		for(int x : right) cout << x << " ";
		cout << endl;*/
		while(q--){
			int x,y;cin >> x >> y;
			if(x > y)  swap(x,y);
			x--;y--;
			if(x == y) cout << 0 << endl;
			else if(v[x] == v[y] || is(v[x],v[y])) cout << (y - x) << endl;
			else{
				if(right[x] < y && right[x] != -1) cout << (y - x) << endl;
				else{
					int val;
					if(left[x] == -1 && right[y] == -1) cout << -1 << endl;
					else if(left[x] == -1){
						val = 2*right[y] - y - x;
						cout << val << endl;
					}
					else if(right[y] == -1){
						val = y + x - 2*left[x];
						cout << val << endl;
					}
					else{
						val = y - x + 2*min(right[y] - y,x - left[x]);
						cout << val << endl;
					}
				}
			}
		}
	}
}