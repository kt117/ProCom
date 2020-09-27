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

ll n, a[200020], b[200020], cnt[200020][2];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)cin >> a[i];
    zep(i, 0, n)cin >> b[i];

    zep(i, 0, n){
        cnt[a[i]][0]++;
        cnt[b[i]][1]++;
    }

    rep(i, 1, n){
        if(cnt[i][0] + cnt[i][1] > n){
            print("No")
            return 0;
        }
    }
    
    priority_queue<vector<ll>> q;
    rep(i, 1, n){
        if(cnt[i][1] > 0)q.push({cnt[i][0] + cnt[i][1], i, cnt[i][1]});
    }
    
    vector<P> u;
    rep(i, 1, n)if(cnt[i][0] > 0)u.push_back(P(cnt[i][0], i));
    sort(u.begin(), u.end(), greater<>());
    
    vector<vector<int>> v(n + 1);
    zep(i, 0, u.size()){
        zep(j, 0, u[i].first){
            auto p = q.top(); q.pop();
            
            if(p[1] == u[i].second){
                auto tmp = p;
                p = q.top(); q.pop();
                q.push(tmp);
            }
            
            v[u[i].second].push_back(p[1]);
            p[2]--;
            if(p[2] > 0)q.push(p);
        }
    }
    
    print("Yes")
    zep(i, 0, n){
        cout << v[a[i]].back() << " ";
        v[a[i]].pop_back();
    }
    cout << endl;
    
    return 0;
}