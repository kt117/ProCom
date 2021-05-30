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

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll f[n]; zep(i, 0, n){cin >> f[i]; f[i]--;}
    
    bool use[n]; memset(use, 0, sizeof(use));
    ll cnt = 0;
    zep(i, 0, n){
        if(!use[i]){
            use[i] = true;

            ll at = i;
            set<ll> s;
            s.insert(i);
            while(true){
                at = f[at];
                if(use[at])break;
                use[at] = true;
                s.insert(at);
            }

            if(s.find(at) != s.end())cnt++;
        }
    }
    
    print((powmod(2, cnt) + MOD - 1) % MOD)

    return 0;
}