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

vi v(1e6+1);

class Kaarti{
public:
    void method(int n){
        rep(i,1,n+1) v[i] = 0;
        int sum = (n * (n+1))/2;
        if(sum & 1){
            cout<<"NO"<<endl;
            return;
        }
        sum /= 2;
        vi a;
        for(int i=n; i>=1; i--){
            if(sum == 0) break;
            if(sum >= i){
                a.pb(i);
                v[i] = 1;
                sum -= i;
            } else {
                a.pb(sum);
                v[sum] = 1;
                break;
            }
        }
        vi b;
        rep(i,1,n+1){
            if(v[i] == 0) b.pb(i);
        }
        cout<<"YES"<<endl;
        cout<<a.size()<<endl;
        disvec(a, a.size());
        cout<<b.size()<<endl;
        disvec(b, b.size());
    }
};

int32_t main(){
    int n;
    cin>>n;
    Kaarti *ob = new Kaarti;
    ob->method(n);
    return 0;
}