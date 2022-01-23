#include<bits/stdc++.h>

#define ll long long
#define N 50

using namespace std;

ll arr[N];

ll fibonacci(int i){
    if (i == 0) return 0;
    else if (i == 1) return 1;
    return fibonacci(i-1) + fibonacci(i-2);
}

int main(){

    struct timespec t1, t2;
    // Using recursion that is not optimized
    // Populating the data
    timespec_get(&t1, TIME_UTC);
    for(int i{}; i < N; i++){
        arr[i] = fibonacci(i);
    }
    

    // Printing the values
    for(int i{}; i < N; i++){
        cout << arr[i] << " ";
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