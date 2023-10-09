#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define pb push_back
using ll=long long;
const int N=1e6+5;

int n,m,u,v,cnt=0,num[N],low[N],res_cnt=0;
bool check[N];
vector <int> a[N],res[N];
stack <int> st;

void dfs(int u) {
    num[u]=low[u]=++cnt;
    st.push(u);
    for (auto v: a[u]) if (!check[v]) if (!num[v]) {
        dfs(v);
        low[u]=min(low[u],low[v]);
    } else low[u]=min(low[u],num[v]);
    if (low[u]==num[u]) {
        int v;
        do {
            v=st.top();
            st.pop();
            check[v]=true;
            res[res_cnt].pb(v);
        } while(v!=u);
        res_cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("MNET");

    cin >> n >> m;
    while (m--) {cin >> u >> v; a[u].pb(v);}
    for (int i=1; i<=n; i++) if (!num[i]) dfs(i);
    cout << res_cnt << "\n";
    for (int i=0; i<res_cnt; i++) {
        for (auto v: res[i]) cout << v << " ";
        cout << "\n";
    }
    return 0;
}

