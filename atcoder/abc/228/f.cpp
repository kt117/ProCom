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

ll h, w, h1, w1, h2, w2, a[1010][1010], conv1[1010][1010], conv2[1010][1010], conv3[1010][1010], conv4[1010][1010];

ll box(ll hi, ll wi, ll hj, ll wj){
    return a[hi][wi] - a[hi][wj] - a[hj][wi] + a[hj][wj];
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> h >> w >> h1 >> w1 >> h2 >> w2;
    rep(i, 1, h)rep(j, 1, w)cin >> a[i][j];

    rep(i, 1, h)rep(j, 1, w)a[i][j] += a[i - 1][j];
    rep(i, 1, h)rep(j, 1, w)a[i][j] += a[i][j - 1];
    
    h2 = min(h2, h1);
    w2 = min(w2, w1);

    rep(i, 1, h - h1 + 1){
        rep(j, 1, w - w1 + 1){
            conv1[i][j] = box(i + h1 - 1, j + w1 - 1, i - 1, j - 1);
        }
    }

    rep(i, 1, h - h2 + 1){
        rep(j, 1, w - w2 + 1){
            conv2[i][j] = box(i + h2 - 1, j + w2 - 1, i - 1, j - 1);
            // cout << conv2[i][j] << " ";
        }
        // cout << endl;
    }

    rep(i, 1, h - h2 + 1){
        multiset<ll> s;

        rep(j, 1, w1 - w2 + 1)s.insert(conv2[i][j]);

        rep(j, 1, w - w1 + 1){
            conv3[i][j] = (*s.rbegin());
            s.erase(s.find(conv2[i][j]));
            s.insert(conv2[i][j + w1 - w2 + 1]);
            // cout << conv3[i][j] << " ";
        }
        // cout << endl;
    }
    
    rep(j, 1, w - w1 + 1){
        multiset<ll> s;

        rep(i, 1, h1 - h2 + 1)s.insert(conv3[i][j]);

        rep(i, 1, h - h1 + 1){
            conv4[i][j] = (*s.rbegin());
            s.erase(s.find(conv3[i][j]));
            s.insert(conv3[i + h1 - h2 + 1][j]);
            // cout << conv4[i][j] << " ";
        }
        // cout << endl;
    }

    ll ans = 0;
    rep(i, 1, h - h1 + 1){
        rep(j, 1, w - w1 + 1){
            ans = max(ans, conv1[i][j] - conv4[i][j]); 
        }
    }
    print(ans)

    return 0;
}