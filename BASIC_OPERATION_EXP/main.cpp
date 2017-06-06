#include <iostream>
#include <math.h>
#include <limits>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fstream>

using namespace std;

//Constants
int ARRAY_CAPACITY = 2000;
int STEP_SIZE = 100;
int NUM_TESTS = 50;
//Function Prototypes
int MinDistance(int A[], int n);
int MinDistance2(int A[], int n);

int main()
{
    std::ofstream min_distance("MinDistance.txt"); // Output file stream
    std::ofstream min_distance2("MinDistance2.txt"); // Output file stream
    srand(time(NULL)); // Seed random
    int A[ARRAY_CAPACITY]; //init array
    for(int i = STEP_SIZE; i <= ARRAY_CAPACITY; i+=STEP_SIZE){
            long average = 0;
            for(int p = 0; p < NUM_TESTS; p++ ){
                        for(int k = 0; k < i; k++){
            A[k] = rand() % i;
        }
        average += (MinDistance(A,i)-i);

            }
        min_distance << i << "," << average/NUM_TESTS << " \n"; // Subtract i to account for i!=j
        min_distance2 << i << "," << MinDistance2(A,i) << " \n";
    }
    min_distance.close(); // Close Stream
    min_distance2.close(); // Close Stream
}
    int MinDistance(int A[], int n){
    int operationCount = 0;
    int dmin = std::numeric_limits<int>::max();
    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                    operationCount++; // Basic operation count
                if((i != j) && ((abs(A[i]-A[j])) < dmin)){
                      operationCount++; // Basic operation count
                      dmin = abs(A[i] - A[j]);
                   }
            }
    }
        return operationCount;
    }

    int MinDistance2(int A[], int n){
    int operationCount = 0;
    int dmin = std::numeric_limits<int>::max();
    for(int i = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                operationCount++; // Basic operation count
                int temp = (abs(A[i]-A[j]));
                if(temp < dmin){
                    dmin = temp;
                }
                   }
            }
        return operationCount;
    }


