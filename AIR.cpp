#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}

int n,s,t,a[101][101],cnt=0;
bool check[101]={false};
vector <int> res;

void dfs(int u) {
    check[u]=true;
    for (int v=1; v<=n; v++) {
        if (a[u][v]==1 and !check[v]) {res.push_back(v); dfs(v);}
    }
    check[u]=false;
    if (u==t) {
        cnt++;
        for (int i=0; i<res.size(); i++) cout << res[i] << " ";
        cout << "\n";
    }
    res.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    file("AIR");

    cin >> n >> s >> t;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
    res.push_back(s);
    dfs(s);
    cout << cnt;
    return 0;
}

