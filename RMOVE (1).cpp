#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
using ll=long long;
const int N=1005;

int n,m,u,v,previ[N][N];
bool meet=false; //meet de check xem co hai con robot gap nhau chua
map <pair<int,int>,pair<int,int>> mp; //mp de luu cap canh truoc do cua u,i
vector <int> a[N],res1,resn;

void trace(int u, int i) {
    res1.pb(u); resn.pb(i);
    if (u!=1 or i!=n) trace(mp[{u,i}].fi,mp[{u,i}].se);
    else {
        REPD(i,res1.size()) cout << res1[i] << " ";
        cout << "\n";
        REPD(i,resn.size()) cout << resn[i] << " ";
    }
}

void bfs(int u,int i) {
    queue <pair<int,int>> q;
    q.push({u,i});
    previ[u][i]=1; //Dat previ[u][i]=1 vi neu de cho no =0 thi no xem nhu la chua di
    while (!q.empty()) {
        tie(u,i)=q.front(); //Lay cho q.front().fi va q.front().se vao u va i
        q.pop();
        for (auto v:a[u]) for (auto j:a[i]) if (!previ[v][j]){
            q.push({v,j});
            previ[v][j]=previ[u][i]+1;
            mp[{v,j}]={u,i};
            if (v==j) {
                meet=true; //Phai dat meet=true thay cho viec dung lenh else o (!previ[v][j]) vi
                           //neu v,j khong di duoc thi se con cap khac van co the nen phai xet tiep
                           //va khong tra -1 lien
                cout << previ[v][j]-1 << "\n"; //previ[u][i]=1 thi in ra previ[v][j] phai -1 di
                trace(v,j);
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("RMOVE");
    //Y tuong o day la dung mang hai chieu de chay cung luc hai con robot
    //Neu chung gap nhau thi co nghia la dinh v == dinh j

    cin >> n >> m;
    REP(i,m) {cin >> u >> v; a[u].pb(v);}
    //Truong hop dac biet neu n=1 va co 1 canh 1,1 thi khong can di va ca hai con robot van dang dung o 1 1
    //Nen phai in ra 0, 1 va 1
    //Neu khong thi se in ra -1 vi canh sau cua {1,1} la {1,1}
    //va canh nay da xet nen se khong cap nhap meet dan den in -1
    if (n==1) {cout << 0 << "\n" << 1 << "\n" << 1; return 0;}
    bfs(1,n);
    if (!meet) cout << -1;
    return 0;
}
