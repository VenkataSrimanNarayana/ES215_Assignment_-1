#include<bits/stdc++.h>
#define N 50
typedef unsigned long long int ull;
typedef long long int ll;

using namespace std;

ull dp[N]{0};


// Using memoization
ull fibonacci(int i){
    //base case
    if ((i == 1) && dp[i] == 0){
        dp[i] = i;
        return dp[i];
    }
    else if (dp[i] == 0 && i != 0){
        dp[i] = fibonacci(i-2) + fibonacci(i-1);
        return dp[i];
    }
    else{
        return dp[i];
    }
}

int main(){
    struct timespec t1, t2;
    // populating the array
    timespec_get(&t1, TIME_UTC);
    fibonacci(N);
    // printing the array
    for(int i{}; i < N; i++){
        cout << dp[i] << " ";
    }
    cout << '\n';
    
    timespec_get(&t2, TIME_UTC);
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
    cout << t << "sec " << nt << "nsec\n";
}