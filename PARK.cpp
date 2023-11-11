#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define fi first
#define se second
#define pb push_back
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
using ll=long long;
const int N=1e6+5;

int n,m,u,v,num[N],low[N],cnt=0,biconnected=0;
vector <int> a[N];
stack <pair<int,int>> st;

void dfs(int u, int pre) {
    num[u]=low[u]=++cnt;
    int child=0;
    for (auto v:a[u]) if (v!=pre) if (!num[v]){
        st.push({u,v});
        child++;
        dfs(v,u);
        low[u]=min(low[u],low[v]);
        if ((u==pre and child>=2) or low[v]>=num[u]) {
            pair <int,int> p={0,0};
            biconnected++;
            while (p!=make_pair(u,v)) {
                p=st.top();
                st.pop();
            }
        }
    } else low[u]=min(low[u],num[v]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("PARK");

    cin >> n >> m;
    REP(i,m) {cin >> u >> v; a[u].pb(v); a[v].pb(u);}
    FOR(i,1,n) if (!num[i]) dfs(i,i);
    cout << biconnected;
    return 0;
}
