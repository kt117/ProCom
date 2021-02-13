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

long long gcd(long long a, long long b){return (b == 0)? a : gcd(b, a % b);}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
  
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll mn = a[0]; zep(i, 0, n)mn = min(mn, a[i]);

    map<ll, ll> s;
    zep(i, 0, n){
        for(ll j = 1; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                if(s.find(j) == s.end()){
                    s[j] = a[i];
                }else{
                    s[j] = gcd(s[j], a[i]);
                }

                ll k = a[i] / j;
                if(s.find(k) == s.end()){
                    s[k] = a[i];
                }else{
                    s[k] = gcd(s[k], a[i]);
                }
            }
        }
    }

    ll ans  = 0;
    for(auto it = s.begin(); it != s.end(); it++){
        if((*it).first <= mn && (*it).first == (*it).second)ans++;
    } 
    print(ans)
    
    return 0;
}