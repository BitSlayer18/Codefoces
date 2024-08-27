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
int32_t  main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
		int t;cin >> t;
		while(t--){
			int n,k;cin >> n >> k;
			vector<int>v(n);
			for(int i = 0;i < n;i++) cin >> v[i];
			sort(v.begin(),v.end());
			vector<int>m(k,-1);
			bool is = true;
			int mx = v[n - 1];
			for(int i = 0;i < n;i++){
				int temp = v[i]%k;
				if((v[i] - m[temp])%(2*k) != 0 && m[temp] != -1){
					is = false;
					break;
				}
				else m[temp] = v[i];
			}
			int range = mx;
			if(!is) cout << -1 << endl;
			else{
				int mn = mx;mx += k - 1;
				//cout << mn << " " << mx << endl;
				for(int i = 0;i < k;i++){
					if(m[i] != -1 && range != m[i]){
						int q = (range - m[i]) /k;
						//cout << q << endl;
						if(q % 2){
							mn = max(m[i] + (q + 1)*k,mn);
						}
						else{
							mx = min(mx,m[i] + (q + 1)*k - 1);
						}
					}
					//cout << mn << " " << mx << endl;
				}
				if(mn <= mx) cout << mn << endl;
				else cout << -1 << endl;
			}
		}
}