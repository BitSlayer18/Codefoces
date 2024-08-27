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
        int n,q;cin >> n >> q;
        string a,b;cin >> a >> b;
        vector<vector<int> > v1(n + 1,vector<int>(26,0)),v2(n + 1,vector<int>(26,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < 26;j++){
                v1[i + 1][j] = v1[i][j];
                v2[i + 1][j] = v2[i][j];
            }
            v1[i + 1][a[i] - 'a'] = v1[i][a[i] -'a'] + 1;
            v2[i + 1][b[i] - 'a'] = v2[i][b[i] -'a'] + 1;
        }
        while(q--){
            int l,r;cin >> l >> r;
            int sum = 0;
            for(int i = 0;i < 26;i++){
                int curr = (v1[r][i] - v1[l - 1][i]) - (v2[r][i] - v2[l - 1][i]);
                if(curr >= 0)
                sum += curr;
            }
            cout << sum << endl;
        }
    }
}