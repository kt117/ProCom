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
    
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(m);

    zep(i, 0, m){
        ll k; cin >> k;
        zep(j, 0, k){
            ll tmp; cin >> tmp; tmp--;
            a[i].push_back(tmp);
        }
        reverse(a[i].begin(), a[i].end());
    }

    vector<vector<ll>> cnt(n);
    zep(i, 0, m){
        cnt[a[i].back()].push_back(i);
    }

    queue<P> q;
    zep(i, 0, n){
        if(cnt[i].size() == 2){
            q.push(P(cnt[i][0], cnt[i][1]));
        }
    }

    ll ans = 0;
    while(!q.empty()){
        P x = q.front();
        q.pop();
        a[x.first].pop_back();
        a[x.second].pop_back();

        if(a[x.first].size()){
            cnt[a[x.first].back()].push_back(x.first);
            if(cnt[a[x.first].back()].size() == 2){
                q.push(P(cnt[a[x.first].back()][0], cnt[a[x.first].back()][1]));
            }
        }
        if(a[x.second].size()){
            cnt[a[x.second].back()].push_back(x.second);
            if(cnt[a[x.second].back()].size() == 2){
                q.push(P(cnt[a[x.second].back()][0], cnt[a[x.second].back()][1]));
            }
        }
        ans++;
    }

    print((ans == n)? "Yes" : "No")
    
    return 0;
}