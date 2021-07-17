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

ll n, a[6060], mp[2020];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, 3 * n)cin >> a[i];

    memset(mp, 0, sizeof(mp));
    mp[a[0]]++;
    mp[a[1]]++;

    ll ans = 0;

    zep(i, 0, n - 1){
        ll x[3] = {a[3 * i + 2], a[3 * i + 3], a[3 * i + 4]};

        zep(k, 0, 3)mp[x[k]]++;

        vector<ll> v;
        rep(j, 1, n)if(mp[j] >= 3)v.push_back(j);

        if(v.size() == 0)continue;

        ans++;

        if(v.size() == 1){
            ll cnt = 0;
            zep(k, 0, 3)if(x[k] == v[0])cnt++;

            mp[v[0]] -= 3;
            rep(j, 1, n)mp[j] = min(mp[j], cnt - 1);
            zep(k, 0, 3)if(x[k] != v[0])mp[x[k]]++;
        }

        if(v.size() == 2){
            ll cnt[2]; memset(cnt, 0, sizeof(cnt));
            zep(k, 0, 3)zep(l, 0, 2)if(x[k] == v[l])cnt[l]++;

            if(cnt[0] == 1 && cnt[1] == 1){
                memset(mp, 0, sizeof(mp));
                zep(k, 0, 3)mp[x[k]]++;
            }

            if(cnt[0] == 1 && cnt[1] == 2){
                rep(j, 1, n)mp[j] = min(mp[j], 1LL);
                mp[v[1]] = 2;
            }

            if(cnt[0] == 2 && cnt[1] == 1){
                rep(j, 1, n)mp[j] = min(mp[j], 1LL);
                mp[v[0]] = 2;
            }
        }

        if(v.size() == 3){
            memset(mp, 0, sizeof(mp));
            zep(k, 0, 3)mp[x[k]]++;
        }

        //print(ans)
    }

    if(mp[a[3 * n - 1]] >= 2)ans++;
    print(ans)

    return 0;
}