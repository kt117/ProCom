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

long long extGcd(long long a, long long b, long long &p, long long &q) {  
    if (b == 0) { p = 1; q = 0; return a; }  
    long long d = extGcd(b, a%b, q, p);  
    q -= a/b * p;  
    return d;  
}

pair<long long, long long> ChineseRem(long long b1, long long m1, long long b2, long long m2) {
  long long p, q;
  long long d = extGcd(m1, m2, p, q);
  if ((b2 - b1) % d != 0) return make_pair(0, -1);
  long long m = m1 * (m2/d);
  long long tmp = (b2 - b1) / d * p % (m2/d);
  long long r = ((b1 + m1 * tmp) % m + m) % m;
  return make_pair(r, m);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        ll x, y, p, q; cin >> x >> y >> p >> q;
        
        ll ans = -1;
        zep(i, x, x + y){
            zep(j, p, p + q){
                auto res = ChineseRem(i, 2 * (x + y), j, p + q);
                if(res.second != -1 && (ans == -1 || ans > res.first)){
                    ans = res.first;
                }
            }
        }
        if(ans == -1){
            print("infinity")
        }else{
            print(ans)
        }
    }
    
    return 0;
}