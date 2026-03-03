#include <iostream>
using namespace std;

int main(){
    int N, s = 1, change = 0, temp;
    bool flag = 1;

    cin >> N;
    int Array[N];

    for (int i = 0; i < N; i++){
        cin >> Array[i];
    }
    
    for(s = 0; flag; s++){
        flag = 0;
        for (int i = N-1; i > s; i--){
            if (Array[i] < Array[i-1]){
                temp = Array[i];
                Array[i] = Array[i-1];
                Array[i-1] = temp; 
                change++;
                flag = 1;
            }
        }
    }

    for (int i = 0; i < N; i++){
        cout << Array[i];
        i != N-1 ? cout << " " : cout << endl;
    }
    cout << change << endl;

    return 0;
}