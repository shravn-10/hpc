#include <iostream>
#include <cstdlib>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv) {
    int rank, size;
    int sum = 0;
    int total_sum = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    srand(rank); 
    sum = rand() % 100;

    cout << "Robot " << rank << " picked " << sum << " mangoes." << endl;

    MPI_Reduce(&sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        cout << "Total Mangoes picked by " << size << " Robots = " << total_sum << endl;
    }

    MPI_Finalize();
    return 0;
}
