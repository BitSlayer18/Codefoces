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
ll count_triplets(ll n, ll x) {
    ll result = 0;
    const ll MAX_A = 1000000; // 10^6

    for (ll a = 1; a <= min(x - 2, MAX_A); ++a) {
        // Calculate the maximum possible value for b+c
        ll max_bc = min(x - a, n / a + 1);
        
        // Calculate the minimum possible value for b+c
        ll min_bc = 2;
        
        // If the range is invalid, continue to next a
        if (max_bc < min_bc) continue;

        for (ll bc = min_bc; bc <= max_bc; ++bc) {
            // Calculate the range for b
            ll min_b = max(1LL, (bc + 1) / 2 - a);
            ll max_b = min(bc - 1, (n - a * bc) / (a + bc));
            
            // If the range is invalid, continue to next bc
            if (max_b < min_b) continue;
            
            // Add the count of valid (b,c) pairs for this a and bc
            result += max_b - min_b + 1;
        }
    }

    return result;
}
int32_t main(){
    int t;cin >> t;
    while(t--){
        int n,x;cin >> n >> x;

    }
}