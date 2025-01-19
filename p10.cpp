#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

int main() {
    int n;
    cout << "Enter the dimension of square matrices: ";
    cin >> n;

    vector<vector<int>> arr1(n, vector<int>(n));
    vector<vector<int>> arr2(n, vector<int>(n));
    vector<vector<int>> res(n, vector<int>(n));

    omp_set_num_threads(64);

    #pragma omp parallel for
        for (int i = 0; i < n; i++) {
            srand(i);
            for (int j = 0; j < n; j++) {
                arr1[i][j] = rand() % 100;
                arr2[i][j] = rand() % 100;
            }
        }
    

    clock_t st, et;
    st = clock();
    
    #pragma omp parallel for
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    res[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
    

    et = clock();
    cout << "Time taken by parallel algorithm: " << (double)(et - st) / CLOCKS_PER_SEC << " seconds\n";

    st = clock();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
            for (int k = 0; k < n; k++) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    et = clock();
    cout << "Time taken by sequential algorithm: " << (double)(et - st) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
    
}
