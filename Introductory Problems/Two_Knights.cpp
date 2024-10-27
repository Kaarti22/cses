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
    void method(int n){
        rep(i,1,n+1){
            if(i == 1){
                cout<<0<<endl;
                continue;
            }
            int low = 1, high = i;
            int max_rows = i/2;
            if(i & 1) max_rows++;
            int cols = i/2;
            int ans = 0;
            rep(row, 1, max_rows+1){
                rep(j,1,cols+1){
                    int c = 0;
                    if(row-1 >= low && j+2 <= high){
                        c++;
                    }
                    if(row+1 <= high && j+2 <= high){
                        c++;
                    }
                    if(row-1 >= low && j-2 >= low){
                        c++;
                    }
                    if(row+1 >= low && j-2 >= low){
                        c++;
                    }
                    if(row+2 <= high && j+1 <= high){
                        c++;
                    }
                    if(row-2 >= low && j+1 <= high){
                        c++;
                    }
                    if(row+2 >= high && j-1 <= low){
                        c++;
                    }
                    if(row-2 >= low && j-1 <= low){
                        c++;
                    }
                    ans += (i * i) - 1 - c;
                }
                ans *= 4;
                int c = 0, j = 1;
                if(row-1 >= low && j+2 <= high){
                    c++;
                }
                if(row+1 <= high && j+2 <= high){
                    c++;
                }
                if(row-1 >= low && j-2 >= low){
                    c++;
                }
                if(row+1 >= low && j-2 >= low){
                    c++;
                }
                if(row+2 <= high && j+1 <= high){
                    c++;
                }
                if(row-2 >= low && j+1 <= high){
                    c++;
                }
                if(row+2 >= high && j-1 <= low){
                    c++;
                }
                if(row-2 >= low && j-1 <= low){
                    c++;
                }
                ans -= 4 * ((i * i) - 1 - c);
                cols -= 2;
            }
            cout<<ans<<endl;
        }
    }
};

int32_t main(){
    int n;
    cin>>n;
    Kaarti *ob = new Kaarti;
    ob->method(n);
    return 0;
}