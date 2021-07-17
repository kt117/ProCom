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
    
    ll n, t; cin >> n >> t;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll m = n / 2;
    set<ll> s;
    zep(bit, 0, (1LL << m)){
        ll sm = 0;
        zep(i, 0, m){
            if((1LL << i) & bit){
                sm += a[i];
            }
        }
        
        if(sm <= t)s.insert(-sm);
    }
    //for(auto it = s.begin(); it != s.end(); it++){print(*it)}

    ll ans = 0;
    ll r = n - m;
    zep(bit, 0, (1LL << r)){
        ll sm = 0;
        zep(i, 0, r){
            if((1LL << i) & bit){
                sm += a[n - 1 - i];
            }
        }
        if(sm <= t){
            auto it = s.lower_bound(-(t - sm));
            ans = max(ans, sm - (*it));
        }
        //print(sm)
    }
    print(ans)

    return 0;
}