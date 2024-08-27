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
int32_t main(){ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin >> t;
    while(t--){
        string s;cin >> s;
        int n = s.length();
        vector<int>v(n + 1,0);
        for(int i = 0;i < n;i++){
            if(s[i] == '0'){
                v[i + 1] = v[i] - 1;
            }
            else v[i + 1] = v[i] + 1;
            //cout << v[i] << endl;
        }
        //for(int x : v) cout << x << " ";
        //cout << endl;
        map<int,int>mp;
        for(int i = 0;i <= n;i++){
            //cout << v[i] << endl;
            mp[v[i]] += n + 1 - i;
            //cout << mp[v[i]] << endl;
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            //cout << mp[v[i]] << endl;
            mp[v[i]] -= n + 1 - i;
            ans += ((i + 1)%mod)*(mp[v[i]]%mod) % mod;
            ans %= mod;
            //cout << ans << endl;
        }
        cout << ans << endl;
    }
}