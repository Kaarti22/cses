#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 1000000007
#define pb push_back
#define popb pop_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define all(v) v.begin(),v.end()

void inparr(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void disarr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void inpvec(vi &v, int n){
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
}

void disvec(vi v, int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int madd(int a,int b) {
    return (a+b)%MOD;
}

int msub(int a,int b){
    return (((a-b)%MOD)+MOD)%MOD;
}

int mmul(int a,int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

class Kaarti{
private:
    vvi dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int i, int j, int n, int m, vector<string>& v, vvi& vis){
        for(auto d: dir){
            int x = i + d[0], y = j + d[1];
            if(x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '.' && vis[x][y] == 0){
                vis[x][y] = 1;
                dfs(x, y, n, m, v, vis);
            }
        }
    }

public:
    void method(vector<string>& v, int n, int m){
        vvi vis(n, vi(m, 0));
        int ans = 0;
        rep(i,0,n){
            rep(j,0,m){
                if(v[i][j] == '.' && vis[i][j] == 0){
                    vis[i][j] = 1;
                    dfs(i, j, n, m, v, vis);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    int n, m;
    cin>>n>>m;
    vector<string> v(n);
    rep(i,0,n) cin>>v[i];
    Kaarti ob;
    ob.method(v, n, m);
    return 0;
}