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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;cin >> n >> m;
    vector<int>a(n),b(n),c(m);
    int mx = 0,mn = 1e18;
    for(int i = 0;i < n;i++) {cin >> a[i]; mx = max(mx,a[i]);mn = min(mn,a[i]);}
    for(int i = 0;i < n;i++) cin >> b[i];
    for(int i = 0;i < m;i++) cin >> c[i];
    vector<int>least(mx + 5,1e17);
    for(int i = 0;i < n;i++){
        least[a[i]] = min(least[a[i]], a[i] - b[i]);
    }
    for(int i = 1;i <= mx;i++){
        least[i] = min(least[i - 1],least[i]);
    }
    vector<int>dp(mx + 5,0);
    for(int i = mn;i <= mx;i++){
        dp[i] = 2 + dp[i - least[i]];
    }
    //for(int i = 1; i <= 10 ;i++) cout << dp[i] << endl;
    int ans = 0;
    for(int i = 0;i < m;i++){
        if(c[i] > mx){
            int val = ceil(double((c[i] - mx))/double(least[mx]));
            c[i] -= val*least[mx];
            ans += 2*val;
        }
        if(c[i] > 0){
        //cout << c[i] << " " << val << " " << ans << endl;
        ans +=dp[c[i]];
        //cout << (2*val + dp[c[i]]) << endl;
        }
    }
    cout << ans << endl;
}