#include <iostream>
#include <ctime>
#include <omp.h>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Number of terms: ";
    cin >> n;

    vector<int> a(n);
    a[0] = 0;
    a[1] = 1;

    clock_t st = clock();
    omp_set_num_threads(2);

    #pragma omp parallel
    {
        #pragma omp single
        {
            cout << "ID of thread involved in the computation of Fibonacci numbers = "
                 << omp_get_thread_num() << endl;
            for (int i = 2; i < n; i++) {
                a[i] = a[i - 2] + a[i - 1];
            }
        }

        #pragma omp single
        {
            cout << "ID of thread involved in the displaying of Fibonacci numbers = "
                 << omp_get_thread_num() << endl;
            cout << "Fibonacci numbers: ";
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    clock_t et = clock();
    double exec_time = (double)(et - st) / CLOCKS_PER_SEC;
    cout << "Time Taken: " << exec_time << " seconds" << endl;

    return 0;
}
