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
        string a,b;cin >> a >> b;
        int ans = a.length() + b.length();
        for(int i = 0;i < b.length();i++){
            bool isfound = false;
            int index;
            for(int j = 0;j < a.length();j++){
                if(b[i] == a[j]){
                    isfound = true;
                    index = j;
                    break;
                }
            }
            //cout << " I equals " << i << endl;
            //cout << isfound << endl;
            if(isfound) {
                int k = i,l = index;
                int count = 0;
                while(l < a.length() && k < b.length()){
                    if(a[l] == b[k]){
                        l++,k++;
                        count++;
                    }
                    else l++;
                }
                int curr = a.length() + b.length() - count;
                ans = std::min(ans,curr);
            }
        }
        cout << ans << endl;
    }
}