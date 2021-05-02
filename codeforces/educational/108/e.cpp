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

long long gcd(long long a, long long b){return (b == 0)? a : gcd(b, a % b);}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n], b[n], c[n], d[n]; zep(i, 0, n)cin >> a[i] >> b[i] >> c[i] >> d[i];

    zep(i, 0, n){
        ll g = gcd(a[i], b[i]);
        a[i] /= g;
        b[i] /= g;

        g = gcd(c[i], d[i]);
        c[i] /= g;
        d[i] /= g;
    }

    map<P, vector<ll>> mp;
    zep(i, 0, n){
        mp[P(b[i], d[i])].push_back(i);
    }

    vector<P> ans;
    for(auto it = mp.begin(); it != mp.end(); it++){
        auto v = (*it).second;
        //cout << (*it).first.first << " " << (*it).first.second << endl;
        vector<vector<ll>> u;
        zep(i, 0, v.size()){
            //cout << a[v[i]] << " " << c[v[i]] << " " << i << endl;
            u.push_back({a[v[i]], c[v[i]], i});
        }
        sort(u.begin(), u.end(), greater<>());

        set<ll> use;
        map<P, vector<ll>> mpp;
        zep(i, 0, u.size()){
            ll k = u[i][2];
            auto p = P((a[k] + b[k]) / gcd(a[k] + b[k], c[k]), c[k] / gcd(a[k] + b[k], c[k]));
            auto q = P(a[k] / gcd(a[k], c[k] + d[k]), (c[k] + d[k]) / gcd(a[k], c[k] + d[k]));

            if(mpp.find(p) != mpp.end() && !mpp[p].empty()){
                while(!mpp[p].empty() && use.find(mpp[p].back()) != use.end())mpp[p].pop_back();
                if(!mpp[p].empty()){
                    ans.push_back(P(mpp[p].back(), k));
                    mpp[p].pop_back();
                }
                if(mpp[p].empty()){mpp.erase(p);}
            }else if(mpp.find(q) != mpp.end() && !mpp[q].empty()){
                while(!mpp[q].empty() && use.find(mpp[q].back()) != use.end())mpp[q].pop_back();
                if(!mpp[q].empty()){
                    ans.push_back(P(mpp[q].back(), k));
                    mpp[q].pop_back();
                }
                if(mpp[q].empty()){mpp.erase(q);}
            }else{
                mpp[p].push_back(k);
                mpp[q].push_back(k);
            }
        }
    }

    print(ans.size())
    for(auto it = ans.begin(); it != ans.end(); it++){
        cout << (*it).first + 1 << " " << (*it).second + 1 << endl;
    }

    return 0;
}