#include<bits/stdc++.h>

#define N 512

typedef long long ll;

using namespace std;

int main(){
    int a[N][N];
    int b[N][N];
    int c[N][N];

    struct timespec t1, t2;

    // Populating a and b
    for(int i{}; i < N; i++){
        for(int j{}; j < N; j++){
            a[i][j] = (((double)rand()/RAND_MAX) * 100);
        } 
    }
    for(int i{}; i < N; i++){
        for(int j{}; j < N; j++){
            b[i][j] = (((double)rand()/RAND_MAX) * 100);
        } 
    }
    // Performing the addition operation
    timespec_get(&t1, TIME_UTC);
    for(int i{}; i < N; i++){
        for(int j{}; j < N; j++){
            c[i][j] = 0;
            for(int x{}; x < N; x++)
                c[i][j] += a[i][x] * b[x][j];
        } 
    }
    timespec_get(&t2, TIME_UTC);

    // Calculating time taken for the give N
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

    // Printing the outputs
    for(int i{}; i < N; i++){
        for(int j{}; j < N; j++){
            cout << a[i][j] << " ";
        } 
        cout << "\n";
    }
    cout << "\n\n";

    for(int i{}; i < N; i++){
        for(int j{}; j < N; j++){
            cout << b[i][j] << " ";
        } 
        cout << "\n";
    }

    cout << "\n\n";
    for(int i{}; i < N; i++){
        for(int j{}; j < N; j++){
            cout << c[i][j] << " ";
        } 
        cout << "\n";
    }
    cout << "\n\n";
    cout << "\nTotal time taken for N = " << N << "\n" << t << "sec " << nt << " nsec\n";
}