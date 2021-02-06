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

ll n, k, p[6000], c[6000];
bool use[6000];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;
    zep(i, 0, n){cin >> p[i]; p[i]--;}
    zep(i, 0, n)cin >> c[i];
    
    bool ng = true;
    zep(i, 0, n)if(c[i] >= 0)ng = false;
    if(ng){
        ll ansn = -INF;
        zep(i, 0, n)ansn = max(ansn, c[i]);
        print(ansn) return 0;
    }

    ll ans = 0;
    
    zep(i, 0, n){
    	if(!use[i]){
    		ll at = i, sm = 0, pe = 0;
    		
    		while(pe == 0 || at != i){
    			use[at] = true;
    			at = p[at];
    			sm += c[at];
    			pe++;
    		}
    		
    		ll res = 0;
    		if(sm > 0)res += (k / pe) * sm;
    		ll rk = k % pe;
    		
    		vector<ll> v;
    		at = i;
            ll cur = 0;
    		zep(j, 0, pe + rk){
    			at = p[at];
    			cur += c[at];
    			v.push_back(cur);
    		}
    		
    		ll resr = 0;
    		priority_queue<P> q;
		    zep(j, 0, pe + rk){
		    	q.push(P(-v[j], j));
		    	while(!q.empty() && j - q.top().second > rk)q.pop();
		    	
		    	resr = max(resr, v[j] + q.top().first);
		    }
		    
		    ans = max(ans, res + resr);
            
            if(k >= pe){
                res = 0;
                if(sm > 0)res += ((k - pe) / pe) * sm;
                rk = pe;

                while(!v.empty())v.pop_back();
                at = i, cur = 0;
                zep(j, 0, pe + rk){
                    at = p[at];
                    cur += c[at];
                    v.push_back(cur);
                }
                
                resr = 0;
                while(!q.empty())q.pop();
                
                zep(j, 0, pe + rk){
                    q.push(P(-v[j], j));
                    while(!q.empty() && j - q.top().second > rk)q.pop();
                    
                    resr = max(resr, v[j] + q.top().first);
                }
                
                ans = max(ans, res + resr);
            }
    	}
    }
    
    print(ans)
    
    return 0;
}
