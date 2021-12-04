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

long long powmod(long long a, long long x, ll mod){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2, mod);
    return (x%2)? (r * r % mod) * a % mod : r * r % mod;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, k, m; cin >> n >> k >> m;
    
    if(m % MOD == 0){
        print(0)
    }else{
        print(powmod(m % MOD, powmod(k % (MOD - 1), n, MOD - 1), MOD))
    }
    
    return 0;
}