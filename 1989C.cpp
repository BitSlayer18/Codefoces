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
        int n;cin >> n;
        vector<int>a(n),b(n);
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int i = 0;i < n;i++) cin >> b[i];
        int neg = 0,pos = 0;
        int av = 0,bv= 0;
        for(int i = 0;i < n;i++){
            if(a[i] == b[i]){
                if(a[i] == -1) neg++;
                else if(a[i] == 1)pos++;
            }
            else{
                if(a[i] > b[i]){
                    av += a[i];
                }
                else bv += b[i];
            }
        }
        int ans = -1e9;
        for(int i = -neg;i <= pos;i++){
            ans = max(ans,min(av + i,bv + (pos - neg - i)));
            //cout << ans << endl;
        }
        cout << ans << endl;
    }
}