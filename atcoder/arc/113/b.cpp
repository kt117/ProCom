#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

long long powmod(long long a, long long x, ll MOD){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2, MOD);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll a, b, c; cin >> a >> b >> c;
    a %= 10;
    vector<ll> v;
    v.push_back(a);
    while(v.back() * a % 10 != v[0]){
        v.push_back(v.back() * a % 10);
    }
    //printa(v, 0, v.size() - 1)
    ll m = v.size();
    print(v[(powmod(b, c, m) + m - 1) % m])
    
    return 0;
}