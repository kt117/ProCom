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
    
    ll n, x, m; cin >> n >> x >> m;

    vector<ll> v = {x};
    bool use[m]; memset(use, 0, sizeof(use)); use[x] = true;
    ll at = x, lst = x;
    
    while(1){
        at = at * at % m;
        lst = at;

        if(use[at])break;
        use[at] = true;

        v.push_back(at);
    }

    vector<ll> u;
    while(v.back() != lst){
        u.push_back(v.back());
        v.pop_back();
    }
    u.push_back(lst);
    v.pop_back();
    reverse(u.begin(), u.end());

    ll ans = 0;
    zep(i, 0, v.size()){
        ans += v[i];
        n--;
        if(n == 0){
            print(ans) return 0;
        }
    }

    ll sm = 0;
    zep(i, 0, u.size())sm += u[i];
    ans += sm * (n / u.size());
    n %= u.size();
    zep(i, 0, n)ans += u[i];
    print(ans)

    return 0;
}