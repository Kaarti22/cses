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
public:
    void method(vi &v, int n, int x){
        vi org = v;
        sort(all(v));
        vi points;
        int i = 0, j = n-1;
        while(i < j){
            if(v[i] + v[j] == x){
                points.pb(v[i]);
                points.pb(v[j]);
                break;
            }
            if(v[i] + v[j] > x) j--;
            else i++;
        }
        if(points.size() == 0){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        vi ans;
        rep(i,0,n){
            if(org[i] == points[0]){
                ans.pb(i);
                break;
            }
        }
        rep(i,0,n){
            if(org[i] == points[1] && ans[0] != i){
                ans.pb(i);
                break;
            }
        }
        cout<<ans[0]+1<<" "<<ans[1]+1<<endl;
    }
};

int32_t main(){
    int n, x;
    cin>>n>>x;
    vi v(n);
    inpvec(v, n);
    Kaarti *ob = new Kaarti;
    ob->method(v, n, x);
    return 0;
}