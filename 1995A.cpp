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
        int n,k;cin >> n >> k;
        int count = 0;
        if(k == 0) cout << 0 << endl;
        else if(k <= n) cout << 1 << endl;
        else{
            count++;
            k -= n;
            for(int i = n - 1;i >= 1 && k > 0;i--){
                if(k <= i) count++;
                else count += 2;
                k -= min(2*i,k);
            }
            cout << count << endl;
            //cout << k << count << endl;
        }
    }
}