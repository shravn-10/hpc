#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of matrix and vector (n): ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    vector<int> vec(n);
    vector<int> res(n);

    time_t st, et;
    st = clock();

    omp_set_num_threads(n);

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 100;
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 100;
    }

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        res[i] = 0;
        for (int j = 0; j < n; j++) {
            res[i] += arr[i][j] * vec[j];
        }
    }

    et = clock();

    cout << "Matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Vector x:" << endl;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    cout << "Result vector y = A * x:" << endl;
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    double execution_time = double(et - st) / CLOCKS_PER_SEC;
    cout << "Execution Time: " << execution_time << " seconds" << endl;

    return 0;
}
