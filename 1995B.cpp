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
int maxpos(int mid,int v2,int p,int m){
    int val = m - mid*p;
    int val1 = floor(double(val)/double(p + 1));
    int t2 = min(v2,val1);
    return mid*p + t2* (p + 1);
}
int32_t main(){
    int t;cin >> t;
    while(t--){
        int n,m;cin >> n >> m;
        vector<int>a(n),b(n);
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int i = 0;i < n;i++) cin >> b[i];
        vector<pair<int,int> >f;
        for(int i  = 0;i < n;i++){
            f.push_back(make_pair(a[i],b[i]));
        }
        int ans = 0;
        sort(f.begin(),f.end());
        for(int i = 1;i < n;i++){
            if(f[i].first - f[i - 1].first != 1) continue;
            int curr = 0;
            int v1 = f[i - 1].second,v2 = f[i].second,p = f[i - 1].first;
            int temp = floor(double(m)/double(p));
            int l = 0, r = min(v1,temp);
            while(l < r){
                cout << l << r << endl;
                int mid = (l + r)/2;
                cout << "mid is" << mid << endl;
                int val1 = maxpos(mid,v2,p,m),val2 = maxpos(l,v2,p,m);
                cout << val1 << " " << val2 << endl;
                if(val1 > val2){
                    l = mid + 1;
                    curr = max(curr,maxpos(mid,v2,p,m));
                }
                else r = mid;
                cout << l << r << endl;
            }
            ans = max(ans,curr);
        }
        cout << ans << endl;
    }
}