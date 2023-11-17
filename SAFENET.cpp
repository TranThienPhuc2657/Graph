#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define fi first
#define se second
using ll=long long;
const int N=1e6+5;

int n,m,u,v,num[N],low[N],cnt=0,res=INT_MIN;
vector <int> a[N];
stack <pair<int,int>> st; //Stack de luu cac canh

void dfs(int u,int pre) {
    num[u]=low[u]=++cnt;
    for (auto v:a[u]) if (v!=pre) if (!num[v]) {
        st.push({u,v}); //Neu nhu do thi co cac canh 1,2; 2,3; 3,1 thi canh 3,1
                        //khong duoc lay vao stack tai gap num[v] roi.
                        //Neu nhu day la bai liet ke cac canh thuoc thanh phan
                        //song lien thong thi chi can in ra them canh st.top().se,u
                        //hay cu the o vi du la 3,1 (st.top={2,3}, u=1)
        dfs(v,u);
        low[u]=min(low[u],low[v]);
        if (low[v]>=num[u]) { //Neu u la khop (khong tinh cai truong hop u==pre va child>=2
                              //vi neu u la goc ma trong do thi chi co 1 thanh phan song lien thong
                              //hay co 1 thanh phan song lien thong noi voi goc thi van tinh cai
                              //song lien thong day
            pair <int,int> p={0,0};
            set <int> s;
            while (p!=make_pair(u,v)) { //Lay cac canh cho toi het u,v
                p=st.top();
                st.pop();
                s.insert(p.fi); //Cho cac dinh da gap vao mot set va sau do dem so luong
                s.insert(p.se);
            }
            res=max(res,int(s.size()));
        }
    } else low[u]=min(low[u],num[v]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("SAFENET");

    cin >> n >> m;
    REP(i,m) {cin >> u >> v; a[u].pb(v); a[v].pb(u);}
    FOR(i,1,n) if (!num[i]) dfs(i,i);
    cout << res;
    return 0;
}
