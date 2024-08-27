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
		vector<pair<int,int> >v(26,make_pair(0,0));
		for(int i = 0;i < n;i++){
			v[s[i] - 'a'].first++;
			v[s[i] - 'a'].second = s[i] - 'a';
		}
		sort(v.rbegin(),v.rend());
		string ans = "";
		int j = 25;
		//cout << "HEllo" << endl;
		while(v[0].first != v[1].first && j != 0){
			if(v[j].first){
				ans += char('a' + v[0].second);
				ans += char('a' + v[j].second);
				v[j].first--;
				v[0].first--;
			}
			else j--;
		}
		int i = 0;
		while(true){
			if(v[i].first && i < 26){
				ans += char('a' + v[i].second);
				v[i].first--;
				i++;
			}
			else {
				if(v[0].first) i = 0;
				else break;
			}
		}
		cout << ans << endl;
	}
}