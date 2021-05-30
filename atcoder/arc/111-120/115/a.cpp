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
    
    ll n, m; cin >> n >> m;
    string s[n]; zep(i, 0, n)cin >> s[i];
    ll t[n];
    zep(i, 0, n){
        reverse(s[i].begin(), s[i].end());
        t[i] = 0;
        zep(j, 0, m){
            if(s[i][j] == '1')t[i] |= (1LL << j);
        }
    }

    ll cnt = 0;
    zep(i, 0, n){
        if(__builtin_popcount(t[i]) % 2)cnt++;
    }

    print(cnt * (n - cnt))
    
    return 0;
}