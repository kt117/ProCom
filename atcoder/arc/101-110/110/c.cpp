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
    ll p[n]; zep(i, 0, n)cin >> p[i];

    map<ll, ll> mp;
    zep(i, 0, n)mp[p[i]] = i;

    vector<ll> ans;
    ll r = n;
    while(r > 1){
        ll at = mp[r];
        mp.erase(r);
        if(at == r - 1){print(-1) return 0;}

        zep(i, 0, r - 1 - at - 1){
            ll nx =  mp[r - 1 - i];
            mp.erase(r - 1 - i);
            if(nx != r - 1 - i){print(-1) return 0;}
        }
        //print(p[at + 1])
        mp[p[at + 1]] = at;
        p[at] = p[at + 1];

        zep(i, 0, r - 1 - at)ans.push_back(at + i);
        r = at + 1;
        /*
        print(at)
        printa(ans, 0, ans.size() - 1)
        print(r)
        for(auto it = mp.begin(); it != mp.end(); it++){cout << (*it).first << " " << (*it).second << endl;}
        */
    }

    zep(i, 0, n - 1){
        print(ans[i] + 1)
    }
    
    return 0;
}