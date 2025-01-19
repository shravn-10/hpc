#include <iostream>
#include <vector>
#include <cstdlib>
#include <omp.h>
using namespace std;

int main() {
    int r, ans = 0;

    cout << "Enter number of sections: ";
    cin >> r;

    vector<vector<int>> arr(r);
    vector<int> size(r);

    omp_set_num_threads(r);

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < r; i++) {
            srand(i);
            int sum = 0;
            size[i] = rand() % 20;
            arr[i].resize(size[i]);

            for (int j = 0; j < size[i]; j++) {
                arr[i][j] = rand() % 100;
                sum += arr[i][j];
            }

            #pragma omp critical
            ans += sum;
        }
    }

    for (int i = 0; i < r; i++) {
        cout << "Section - " << i << " ( " << size[i] << " Items ) : ";
        for (int j = 0; j < size[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Total Amount: " << ans << endl;

    return 0;
}
