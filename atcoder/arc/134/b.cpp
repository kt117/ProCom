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
    string s; cin >> s;

    vector<P> v(n);
    zep(i, 0, n)v[i] = P(s[i] - 'a', -i);
    sort(v.begin(), v.end());

    ll l = 0, rb = n, at = 0;
    while(l < rb && at < n){
        ll r = -v[at].second;
        if(l < r && r < rb){
            if(s[r] < s[l]){
                auto tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                rb = r;
                l++;
                at++;
            }else{
                l++;
            }
        }else{
            at++;
        }
    }
    print(s)
    
    return 0;
}