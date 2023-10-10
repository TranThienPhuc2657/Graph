#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second
const int N=1005;

int n,m,u,v,i,j,trace[N][N],meet=-1;
vector <int> a[N],res_u,res_i;
map < pair<int,int> , pair<int,int> > previ;

void duyet(int u, int i) {
    res_u.pb(u);
    res_i.pb(i);
    if (u==1 and i==n){
        reverse(res_u.begin(),res_u.end());
        reverse(res_i.begin(),res_i.end());
        for (auto v:res_u) cout << v << " ";
        cout << "\n";
        for (auto v:res_i) cout << v << " ";
    } else duyet(previ[{u,i}].fi,previ[{u,i}].se);
}

void bfs(int u, int i) {
    queue < pair<int,int> > q;
    q.push({u,i});
    trace[u][i]=1;
    while (!q.empty()) {
        for (auto v:a[u]) for (auto j:a[i]) if (!trace[v][j]) {
            trace[v][j]=trace[u][i]+1;
            previ[{v,j}]={u,i};
            if (v==j) {meet=v; return;}
            q.push({v,j});
        }
        q.pop();
        u=q.front().fi;
        i=q.front().se;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("RMOVE");

    cin >> n >> m;
    while (m--) {cin >> u >> v; a[u].pb(v);}
    if (n==1) {cout << 0 << "\n" << 1 << "\n" << 1; return 0;}
    bfs(1,n);
    if (meet==-1) cout << meet;
    else {cout << trace[meet][meet]-1 << "\n"; duyet(meet,meet);}
    return 0;
}
