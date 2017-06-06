#include <iostream>
#include <math.h>
#include <limits>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Function Prototypes
int MinDistance(int A[], int n);
int MinDistance2(int A[], int n);

// Constants
int ARRAY_CAPACITY = 20000;
int STEP_SIZE = 1000;
int NUM_TESTS = 50;

int main()
{
    std::ofstream min_distance("MinDistance_execution.txt"); // Output file stream
    std::ofstream min_distance2("MinDistance2_execution.txt"); // Output file stream
    srand(time(NULL)); // Seed random
    int A[ARRAY_CAPACITY]; // Init array
    for(int i = STEP_SIZE; i <= ARRAY_CAPACITY; i+=STEP_SIZE){
        long avg_mindistance = 0, avg_mindistance2 = 0;
        for(int p = 0; p < NUM_TESTS; p++){
            for(int k = 0; k < i; k++){
                A[k] = rand() % i;
            }
            high_resolution_clock::time_point t1 = high_resolution_clock::now(); // Start timer
            MinDistance(A,i); // Run algorithm
            high_resolution_clock::time_point t2 = high_resolution_clock::now(); // End timer
            auto duration = duration_cast<microseconds>( t2 - t1 ).count();
            avg_mindistance += duration; // Add totals for md
            t1 = high_resolution_clock::now();
            MinDistance2(A,i); // Run algorithm
            t2 = high_resolution_clock::now();
            auto duration_2 = duration_cast<microseconds>( t2 - t1 ).count();
            avg_mindistance2 += duration_2; // Add totals for md2
        }
        min_distance << i << "," << avg_mindistance/NUM_TESTS << " \n"; // Average total and send to txt file
        min_distance2 << i << "," << avg_mindistance2/NUM_TESTS << " \n";
    }
    min_distance.close(); // Close Stream
    min_distance2.close(); // Close Stream
}
int MinDistance(int A[], int n){
    int dmin = std::numeric_limits<int>::max();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i != j) && ((abs(A[i]-A[j])) < dmin)){
                dmin = abs(A[i] - A[j]);
            }
        }
    }
    return dmin;
}

int MinDistance2(int A[], int n){
    int dmin = std::numeric_limits<int>::max();
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            int temp = (abs(A[i]-A[j]));
            if(temp < dmin){
                dmin = temp;
            }
        }
    }
    return dmin;
}


