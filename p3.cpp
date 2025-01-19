#include <iostream>
#include <ctime>
#include <omp.h>
#include <iomanip>

using namespace std;

int main() {
    int num;
    cout << "Enter the number of steps: ";
    cin >> num;

    time_t st, et;
    st = clock();

    double step = 1.0 / (double)num;
    double pi = 0.0;

    #pragma omp parallel for reduction(+:pi)
    for (int i = 0; i < num; i++) {
        double x = (i + 0.5) * step;
        double local_pi = (4.0 * step) / (1 + x * x);
        pi += local_pi;
    }

    et = clock();
    double exec_time = double(et - st) / CLOCKS_PER_SEC;

    cout << "Time Taken: " << exec_time << " seconds\n";
    cout << fixed << setprecision(16) << "Value of Pi = " << pi << "\n";

    return 0;
}
