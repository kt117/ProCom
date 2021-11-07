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

string f(vector<string> s, string t, ll k){
    sort(s.begin(), s.end());
    if(k == 1)return t + s[0];

    ll n = s.size();
    vector<string> p(n);
    zep(i, 0, n){
        p[i] = s[i];
        zep(j, 0, n){
            if(j != i)p[i] += s[j];
        }
    }
    // zep(i, 0, n)print(s[i])

    vector<pair<string, ll>> q(n);
    zep(i, 0, n)q[i] = make_pair(p[i], i);
    sort(q.begin(), q.end());

    vector<string> u;
    zep(i, 0, n)if(i != q[0].second)u.push_back(s[i]);
    return f(u, t + s[q[0].second], k - 1);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<string> s(n); zep(i, 0, n)cin >> s[i];

    print(f(s, "", k))
    
    return 0;
}