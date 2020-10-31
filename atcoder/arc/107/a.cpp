#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll a, b, c; cin >> a >> b >> c;
    ll d = (MOD + 1) / 2;
    print(a * (a + 1) % MOD * d % MOD * b % MOD * (b + 1) % MOD * d % MOD * c % MOD * (c + 1) % MOD * d % MOD)

    return 0;
}