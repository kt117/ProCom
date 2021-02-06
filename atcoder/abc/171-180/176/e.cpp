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
    
    ll H, W, m; cin >> H >> W >> m;
    ll h[m], w[m]; zep(i, 0, m)cin >> h[i] >> w[i];

    map<ll, ll> mph, mpw;
    set<P> s;

    zep(i, 0, m){
        if(mph.find(h[i]) == mph.end())mph[h[i]] = 0;
        if(mpw.find(w[i]) == mpw.end())mpw[w[i]] = 0;

        mph[h[i]]++;
        mpw[w[i]]++;
        s.insert(P(h[i], w[i]));
    }
    
    ll mxh = 0, mxw = 0;
    for(auto it = mph.begin(); it != mph.end(); it++)mxh = max(mxh, (*it).second);
    for(auto it = mpw.begin(); it != mpw.end(); it++)mxw = max(mxw, (*it).second);

    vector<ll> sh, sw;
    for(auto it = mph.begin(); it != mph.end(); it++)if((*it).second == mxh)sh.push_back((*it).first);
    for(auto it = mpw.begin(); it != mpw.end(); it++)if((*it).second == mxw)sw.push_back((*it).first);

    //printa(sh, 0, sh.size() - 1)
    //printa(sw, 0, sw.size() - 1)

    if(sh.size() * sw.size() > m){
        print(mxh + mxw)
    }else{
        zep(i, 0, sh.size()){
            zep(j, 0, sw.size()){
                if(s.find(P(sh[i], sw[j])) == s.end()){
                    print(mxh + mxw) return 0;
                }
            }
        }
        print(mxh + mxw - 1)
    }

    return 0;
}