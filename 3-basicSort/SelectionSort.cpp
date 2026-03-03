#include <iostream>
using namespace std;

int selectionSort(int*, int);

int main(){
    int N;
    cin >> N;

    int Array[N];
    for (int i = 0; i < N; i++){
        cin >> Array[i];
    }

    int swap = selectionSort(Array, N);
    for (int i = 0; i < N; i++){
        cout << Array[i];
        i == N-1 ? cout << endl : cout << " ";
    }

    cout << swap << endl;

    return 0;
}

int selectionSort(int *A, int N){
    int min, temp, swap = 0;
    for (int i = 0; i < N-1; i++){
        min = i;
        for (int j = i; j < N; j++){
            if (A[min] > A[j]){
                min = j;
            }
        }
        if (i != min){
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            swap++;
        }
    }
    return swap;
}