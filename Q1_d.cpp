#include<bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

#define N 50

using namespace std;

ull dp[N]{};

int main(){
    //using tabulation : bottom-up
    //populating the data
    struct timespec t1, t2;
    timespec_get(&t1, TIME_UTC);
    dp[0] = 0;
    dp[1] = 1;
    for(int i{2}; i < N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    timespec_get(&t2, TIME_UTC);

    //printing the values
    for(int i{}; i < N; i++){
        cout << dp[i] << " ";
    }
    ll nt = 0, t = 0;
    t = (t2.tv_sec - t1.tv_sec);
    nt = (t2.tv_nsec - t1.tv_nsec);
    if (nt >= 1e9){
        t += nt/1e9;
        nt = nt%(ll)1e9;
    }
    else if  (nt < 0){
        t += nt/1e9;
        nt = 1e9 + nt%(ll)1e9; 
    }
    cout << '\n';
    cout << t << "sec " << nt << "nsec\n";
}