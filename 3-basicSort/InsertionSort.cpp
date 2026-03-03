#include <iostream>

using namespace std;

int* InsertionSort(int A[], int N, int print = 0){
    int i, j, v;
    for (i = 1; i < N; i++){
        v = A[i];
        for (j = i-1; j >= 0 && A[j] > v; j--){
            A[j+1] = A[j];
        }
        A[j+1] = v;
        if (print == 1){
            for (int p = 0; p < N; p++){
                cout << A[p];
                p != N-1 ? cout << " " : cout << "\n";
            }
        }
    }
    return A;
}

int main(){
    int N, value, j;
    cin >> N;
    int Array[N];
    for (int i = 0; i < N; i++){
        cin >> Array[i];
    }

    for (j = 0; j < N; j++){
        cout << Array[j];
        j != N-1 ? cout << " " : cout << "\n";
    }
    
    InsertionSort(Array, N, 1);

    return 0;
}

