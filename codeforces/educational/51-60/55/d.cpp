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
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll sm = 0;
    vector<ll> v, c;
    zep(i, 0, n){
        if(a[i] == 1){
            c.push_back(i);
        }else{
            v.push_back(i);
        }
        sm += a[i];
    }

    if(sm < 2 * (n - 1)){
        print("NO")
        return 0;
    }

    ll m = v.size();
    cout << "YES " << m + min(int(c.size()), 2) - 1 << endl; 
    
    vector<P> ans;
    
    zep(i, 0, m - 1){
        ans.push_back(P(v[i], v[i + 1]));
        a[v[i]]--;
        a[v[i + 1]]--;
    }

    if(c.size() > 0){
        ans.push_back(P(v[m - 1], c.back()));
        a[v[m - 1]]--;
        c.pop_back();
    }

    ll at = 0;
    zep(i, 0, c.size()){
        while(a[v[at]] == 0)at++;

        ans.push_back(P(v[at], c[i]));
        a[v[at]]--;
    }

    print(ans.size())
    zep(i, 0, ans.size())cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;

    return 0;
}