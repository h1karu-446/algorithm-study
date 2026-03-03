#include <iostream>
using namespace std;

void bubbleSort(int Array[], int N){
    int flag = 1;
    for (int i = 0; flag; i++){
        flag = 0;
        for (int j = N-1; j > i; j--){
            if (Array[j-1] > Array[j]){
                int t = Array[j];
                Array[j] = Array[j-1];
                Array[j-1] = t;
                flag = 1;
            }
        }
    }
}

int main(){
    int N;
    cin >> N;

    int Array[N];
    for (int i = 0; i < N; i++){
        cin >> Array[i];
    }
    
    bubbleSort(Array, N);

    for (int i = 0; i < N; i++){
        cout << Array[i];
        i != N-1 ? cout << " " : cout << endl;
    }

    return 0;
}