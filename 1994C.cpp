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
int32_t main(){
    int t;cin >> t;
    while(t--){
        int n,x; cin >> n >> x;
        vector<int>v(n);
        for(int i = 0;i < n;i++) cin >> v[i];
        vector<int>dp(n + 1,0);
        vector<int>pre(n + 1,0);
        for(int i = 0;i < n;i++){
            pre[i + 1] = pre[i] + v[i];
        }
        if(v[n - 1] <= x) dp[n - 1]++;
        for(int i = n - 2;i >= 0;i--){
            int diff = upper_bound(pre.begin(),pre.end(),pre[i] + x) - pre.begin();
            diff--;
            if(diff == n){
                dp[i] = n - i;
            }
            else dp[i] = dp[diff + 1] + diff - i;
            //cout << "difference is" << diff << endl;
        }
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += dp[i];
            //cout << dp[i] << endl;
        }
        cout << sum << endl; 
    }
}