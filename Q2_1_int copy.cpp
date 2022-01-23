#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    vector<pair<int, ll>> t;
    for(int N{32}; N <= 512; N *= 2){
        
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

        // calculating and stroing the time for each N
        ll nst = 0;
        int st = 0;
        st = (t2.tv_sec - t1.tv_sec);
        nst = (t2.tv_nsec - t1.tv_nsec);
        if (nst >= 1e9){
            st += nst/1e9;
            nst = nst%(ll)1e9;
        }
        else if  (nst < 0){
            st += nst/1e9;
            nst = 1e9 + nst%(ll)1e9; 
        }
        t.push_back(make_pair(st, nst));
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
    }
    
    // Printing the time taken for each N
    int cnt{32};
    for(auto &x : t){
        cout << cnt << ": " << x.first << "sec " << x.second << "nsec\n";
        cnt *= 2;
    }
    
    // Printing the total time taken by the program
    int st = 0;
    ll nst = 0;
    for(auto &x : t){
        st += x.first;
        nst += x.second;
        if (nst >= 1e9){
            st += nst/1e9;
            nst = nst%(ll)1e9;
        }
        else if  (nst < 0){
            st += nst/1e9;
            nst = 1e9 + nst%(ll)1e9; 
        }
    }
    cout << "\nTotal time taken for all N,: \n" << st << "sec " << nst << " nsec\n";
}