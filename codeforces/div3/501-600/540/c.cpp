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
    ll m = n * n;
    ll a[m]; zep(i, 0, m)cin >> a[i];

    ll cnt[1010]; memset(cnt, 0, sizeof(cnt));
    zep(i, 0, m)cnt[a[i]]++;

    vector<vector<ll>> v(3);
    rep(i, 1, 1000){
        if(cnt[i] / 4 > 0){
            zep(j, 0, cnt[i] / 4)v[0].push_back(i);
            cnt[i] %= 4;
        }

        if(cnt[i] / 2 > 0){
            zep(j, 0, cnt[i] / 2)v[1].push_back(i);
            cnt[i] %= 2;
        }

        if(cnt[i] > 0){
            zep(j, 0, cnt[i])v[2].push_back(i);
        }
    }

    ll ans[n + 1][n + 1]; memset(ans, 0, sizeof(ans));
    
    rep(i, 1, n / 2){
        rep(j, 1, n / 2){
            if(v[0].empty()){print("NO") return 0;}
            ans[i][j] = v[0].back(); v[0].pop_back();
        }
    }

    while(!v[0].empty()){
        v[1].push_back(v[0].back());
        v[1].push_back(v[0].back());
        v[0].pop_back();
    }
    
    if(n % 2 == 1){
        rep(i, 1, n / 2){
            if(v[1].empty()){print("NO") return 0;}
            ans[i][n / 2 + 1] = v[1].back(); v[1].pop_back();
            if(v[1].empty()){print("NO") return 0;}
            ans[n / 2 + 1][i] = v[1].back(); v[1].pop_back();
        }

        ans[n / 2 + 1][n / 2 + 1] = v[2][0];
    }

    print("YES")
    rep(i, 1, n){
        rep(j, 1, n){
            cout << ans[min(i, n - i + 1)][min(j, n - j + 1)] << " ";
        }
        cout << endl;
    }

    return 0;
}