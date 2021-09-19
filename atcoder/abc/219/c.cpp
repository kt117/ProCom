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
    
    string x; cin >> x;
    ll n; cin >> n;
    string s[n]; zep(i, 0, n)cin >> s[i];

    map<ll, ll> mp;
    zep(i, 0, 26){
        mp[x[i] - 'a'] = i;
    }

    vector<pair<string, ll>> v;
    zep(i, 0, n){
        string t;
        t = s[i];
        zep(j, 0, t.size()){
            t[j] = 'a' + mp[s[i][j] - 'a'];
        }

        v.push_back(make_pair(t, i));
    }
    sort(v.begin(), v.end());
    zep(i, 0, n){
        print(s[v[i].second])
    }
    
    return 0;
}