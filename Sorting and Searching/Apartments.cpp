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
    void method(vi &a, int n, vi& b, int m, int k){
        sort(all(a));
        sort(all(b));
        int i = 0, j = 0;
        int ans = 0;
        while(i < n && j < m){
            int diff = abs(a[i] - b[j]);
            if(diff <= k){
                ans++;
                i++;
                j++;
            } else if(a[i] > b[j]){
                j++;
            } else {
                i++;
            }
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    int n, m, k;
    cin>>n>>m>>k;
    vi a(n);
    inpvec(a, n);
    vi b(m);
    inpvec(b, m);
    Kaarti *ob = new Kaarti;
    ob->method(a, n, b, m, k);
    return 0;
}