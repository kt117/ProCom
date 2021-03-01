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

ll scnt[10], tcnt[10];

bool win(){
    ll a = 0;
    rep(i, 1, 9){
        a += i * pow(10, scnt[i]);
    }

    ll b = 0;
    rep(i, 1, 9){
        b += i * pow(10, tcnt[i]);
    }
    //cout << a << " " << b << endl;
    return a > b;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll k; cin >> k;
    string s, t; cin >> s >> t;
    
    vector<ll> cnt(10, k);
    zep(i, 0, 4){
        scnt[s[i] - '0']++;
        cnt[s[i] - '0']--;
    }

    zep(i, 0, 4){
        tcnt[t[i] - '0']++;
        cnt[t[i] - '0']--;
    }
    //printa(scnt, 1, 9)
    ll ans = 0;
    rep(i, 1, 9){
        if(cnt[i] > 0){
            ll x = cnt[i];
            cnt[i]--;
            scnt[i]++;
            rep(j, 1, 9){
                if(cnt[j] > 0){
                    ll tmp = x * cnt[j];
                    cnt[j]--;
                    tcnt[j]++;
                    //cout << i << " " << j << endl;
                    if(win())ans += tmp;
                    tcnt[j]--;
                    cnt[j]++;
                }
            }
            scnt[i]--;
            cnt[i]++;
        }
    }
    cout << fixed << setprecision(20) << double(ans) / ((9 * k - 8) * (9 * k - 9)) << endl;

    return 0;
}