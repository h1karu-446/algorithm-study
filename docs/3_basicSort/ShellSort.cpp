#include <iostream>

using namespace std;

void shellSort(int*, int);
int insertionSort(int*, int, int);

int main(){
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    shellSort(A, N);

    return 0;
}

void shellSort(int *A, int N){
    //knuth法で最初のgapを決める
    int G[100];
    int m = 0, gap = 1, cnt=0;

    //gapを求める
    do {
        G[m] = gap;
        m++;
        gap = gap*3+1;
    } while(gap < N);
    m--;

    //gapの数とgapを表示
    int len = m;
    cout << m+1 << endl;
    while(m >= 0){
        cout << G[m];
        m != 0 ? cout << " ": cout << endl;
        m--;
    }

    //ソート
    for (int i = len; i >= 0; i--){
        cnt += insertionSort(A, N, G[i]);
    }
    cout << cnt << endl;

    //ソートされた整列の表示
    for (int i = 0; i < N; i++){
        cout << A[i] << endl;
    }
}

int insertionSort(int *A, int N, int gap){
    int v, j, cnt = 0;

    for(int i = gap; i < N; i++){
        v = A[i];
        j = i - gap;

        while (j >= 0 && v < A[j]){
            A[j+gap] = A[j];
            cnt++;
            j -= gap;
        }
        A[j+gap] = v;
    }

    return cnt;
}