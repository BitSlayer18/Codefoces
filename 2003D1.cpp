#include<bits/stdc++.h> 
using namespace std; 
#define int long long  
int sum(int x) { 
    return x*(x+1)/2; 
} 
int interval(int l,int r) { 
    return sum(r)-sum(l-1); 
} 
void solve() { 
    int n,m,s=0; 
    cin >> n >> m; 
    for(int i=1;i<=n;++i) { 
        int l; 
        cin >> l; 
        set<int> t; 
        for(int i=1,x;i<=l;++i) { 
            cin >> x; 
            t.insert(x); 
        } 
        bool flag=true; 
        for(int i=0;;++i) { 
            if(!t.count(i)) { 
                if(flag) flag=false; 
                else { 
                    s=max(s,i); 
                    break; 
                } 
            } 
        } 
    } 
    if(m<=s) cout << s*(m+1) << endl; 
    else cout << s*(s+1)+interval(s+1,m) << endl; 
} 
signed main() { 
    cin.tie(0);cout.tie(0); 
    ios_base::sync_with_stdio(0); 
    int T=1;cin >> T;while(T--) solve(); 
}