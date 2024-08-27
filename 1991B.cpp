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
        vector<int>b(n - 1);
        for(int i = 0;i < n - 1;i++) cin >> b[i];
        vector<vector<int> > v(n - 1,vector<int>(31,0));
        for(int i = 0;i < n - 1;i++){
            for(int j = 0;j < 31;j++){
                if(b[i] & (1<<j)){
                    v[i][j] = 1;
                }
            }
        }
        bool is = true;
        for(int j = 0;j < 31;j++){
            for(int i = 0;i < n - 3;i++){
                if(v[i][j] == 1 && v[i + 1][j] == 0 && v[i + 2][j] == 1){
                    is = false;
                    break;
                }
            }
        }
        //cout << is << endl;
        if(!is) cout << -1 << endl;
        else{
            vector<bitset<31> > ans(n);
            for(int j = 0;j < 31;j++){
                ans[0][j] = v[0][j];
                for(int i = 0;i < n - 2;i++){
                    if(v[i][j] == 1){
                        ans[i + 1][j] = 1;
                    }
                    else if(v[i][j] == 0 && v[i + 1][j] == 0) ans[i + 1][j] = 0;
                    else{
                        ans[i + 1][j] = 1;
                    }
                }
                ans[n - 1][j] = v[n - 2][j];
            }
            /*for(int i = 0;i < n;i++){
                for(int j = 0;j < 5;j++) cout << v[i][j] << " ";
                cout << endl;
            }*/
            for(int i = 0;i < n;i++) cout << ans[i].to_ullong() << " ";
            cout << endl;
        }
    }
}