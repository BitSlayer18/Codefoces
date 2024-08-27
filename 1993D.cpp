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
int n,k;
bool is(int x){
	vector<int>b(n);
	for(int i = 0;i < n;i++){
		if(v[i] >= x) b[i] = 1;
		else b[i] = -1;
	}
	vector<int>dp(n);
	dp[0] = b[0];
	for(int i = 1;i < n;i++){
		if(i % k == 0) dp[i] = max(dp[i - k],b[i]);
		else{
			dp[i] = dp[i - 1] + b[i];
			if(i > k) dp[i] = max(dp[i],dp[i - k]);
		}
	}
	if(dp[n - 1] > 0) return true;
	else return false;
}
int32_t  main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;cin >> t;
	while(t--){
		cin >> n >> k;
		v.clear(),v.resize(n);
		for(int i = 0;i < n;i++) cin >> v[i];
		int l = 1,r = 1e11;
		int ans = 1;
		while(l < r){
			int mid = (l + r)/2;
			if(is(mid)){
				ans = max(ans,mid);
				l = mid + 1;
			}
			else r = mid;
		}
		cout << ans << endl;
	}
}