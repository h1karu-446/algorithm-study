#include <iostream>

using namespace std;
static int MAX = -2000000001;

int main(){
    int n;
    cin >> n;
    int R[n];
    
    for (int i = 0; i < n; i++){
        cin >> R[i];
    }

    int minR = R[0];

    for (int i = 1; i < n; i++){
        if (R[i] - minR > MAX){
            MAX = R[i]-minR;
        }
        if (minR > R[i]){
            minR = R[i];
        }
    }

    cout << MAX << endl;

    return 0;
}