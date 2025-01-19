#include <iostream>
#include <omp.h>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    int n, max_index = 0;
    double max_cgpa = 0.0;

    cout << "Enter the number of students: ";
    cin >> n;

    vector<double> cgpa(n);

    for (int i = 0; i < n; i++) {
        cgpa[i]=rand()%1000/100.0;
    }
    
    for (int i = 0; i < n; i++) {
        cout<<cgpa[i]<<" ";
    }

    clock_t st = clock();

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        #pragma omp critical
        {
            if (cgpa[i] > max_cgpa) {
                max_cgpa = cgpa[i];
                max_index = i;
            }
        }
    }

    clock_t et = clock();
    double time_taken = double(et - st) * 1000.0 / CLOCKS_PER_SEC;

    cout << "\nTime Taken: " << time_taken << " ms" << endl;
    cout << "The student with the highest CGPA is Student " << max_index + 1 << " with a CGPA of " << max_cgpa << endl;

    return 0;
}
