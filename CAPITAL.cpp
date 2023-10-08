#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define pb push_back
using ll=long long;
const int N=3e5+5;

int n,m,u,v,cnt=0,num[N],low[N],joint[N];
vector <int> a[N];

void dfs(int u, int pre) {
    int child=0;
    num[u]=low[u]=++cnt;
    for (auto v: a[u]) {
        if (v==pre) continue;
        if (!num[v]) {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            child++;
            if (u==pre) {if (child>=2) joint[u]++;}
            else if (low[v]>=num[u]) joint[u]++;
        } else low[u]=min(low[u],num[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("CAPITAL");

    cin >> n >> m;
    while (m--) {cin >> u >> v; a[u].pb(v); a[v].pb(u);}
    for (int i=1; i<=n; i++) if (!num[i]) dfs(i,i);
    int res=1;
    for (int i=2; i<=n; i++) if (joint[i]>joint[res]) res=i;
    cout << joint[res]+1 << " " << res;
    return 0;
}

