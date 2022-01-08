#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    string s, t; cin >> s >> t;
    ll x = (s[0] + 26 - t[0]) % 26;

    bool ans = true;
    zep(i, 0, s.size()){
        if((s[i] + 26 - t[i]) % 26 != x)ans = false;
    }
    print(ans? "Yes" : "No")
    
    return 0;
}