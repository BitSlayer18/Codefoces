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
int32_t  main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
		int t;cin >> t;
		while(t--){
			int n;cin >> n;
			string s;cin >> s;
			int ans = 0;
			int a = 0,b = 0,c = 0,d = 0,q = 0;
			for(int i = 0;i < 4*n;i++){
				if(s[i] == 'A') a++;
				else if(s[i] == 'B') b++;
				else if(s[i]== 'C') c++;
				else if(s[i] == 'D') d++;
				else q++;
			}
			//cout << a << b << c << d << endl;
			ans = min(a,n)+min(b,n)+min(c,n)+min(d,n);
			cout << ans << endl;
		}
}