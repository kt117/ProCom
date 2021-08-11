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
    
    ll q; cin >> q;
    
    priority_queue<ll, vector<ll>, greater<ll>> p;
    vector<ll> ans;
    ll cnt = 0;

    while(q--){
        ll f; cin >> f;

        if(f == 1){
            ll x; cin >> x;
            p.push(x - cnt);
        }else if(f == 2){
            ll x; cin >> x;
            cnt += x;
        }else{
            ans.push_back(p.top() + cnt);
            p.pop();
        }
    }
    
    zep(i, 0, ans.size())print(ans[i])

    return 0;
}