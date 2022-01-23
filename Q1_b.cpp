#include<bits/stdc++.h>

#define N 50

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ull arr[N];

int main(){
    struct timespec t1, t2;
    // Using for loops without optimizing
    timespec_get(&t1, TIME_UTC);
    arr[0] = 0;
    arr[1] = 1;
    for(int i{2}; i < N; i++){
        ull prev1 = 1, prev2 = 0, curr = 0;
        for(int j{2}; j <= i; j++){
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        arr[i] = curr;
    }
    timespec_get(&t2, TIME_UTC);

    //printing the values
    for(int i{}; i < N; i++){
        cout << arr[i] << " ";
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
    return 0;
}