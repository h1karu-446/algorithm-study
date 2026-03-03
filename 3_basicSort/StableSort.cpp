#include <iostream>
#include <string>
#include "3_basic"

using namespace std;

struct Card {
    char suit, value;
};

void bubbleSort(Card*, int N);
void selectionSort(Card*, int N);
bool checkStable(const Card*, const Card*, int N);

int main(){
    int N;
    cin >> N;

    Card C[N], CB[N], CS[N];

    for (int i = 0; i < N; i++){
        cin >> C[i].suit >> C[i].value;
    }
    for (int i = 0; i < N; i++){
        CB[i] = C[i];
        CS[i] = C[i];
    }

    bubbleSort(CB, N);
    selectionSort(CS, N);

    //bubbleソートの出力
    for (int i = 0; i < N; i++){
        i != 0 ? cout << " " : cout << "";
        cout << CB[i].suit << CB[i].value;
    }
    cout << endl;
    checkStable(C, CB, N) ? cout << "Stable" << endl : cout << "Not stable" << endl;

    //selectionソートの出力
    for (int i = 0; i < N; i++){
        i != 0 ? cout << " " : cout << "";
        cout << CS[i].suit << CS[i].value;
    }
    cout << endl;
    checkStable(C, CS, N) ? cout << "Stable" << endl : cout << "Not stable" << endl;

    return 0;
}

void bubbleSort(Card *card, int N){
    Card temp;
    int s;
    bool flag=1;

    for (s = 0; flag; s++){
        flag = 0;
        for (int i = N-1; i > s; i--){
            if ((int)card[i].value < (int)card[i-1].value){
                flag = 1;
                temp = card[i];
                card[i] = card[i-1];
                card[i-1] = temp;
            }
        }
    }
}

void selectionSort(Card *card, int N){
    Card temp;
    int min;

    for (int i = 0; i < N-1; i++){
        min = i;

        for(int j = i+1; j < N; j++){
            if ((int)card[min].value > (int)card[j].value){
                min = j;
            }
        }
        if (min != i){
            temp = card[i];
            card[i] = card[min];
            card[min] = temp;
        }
    }
}

bool checkStable(const Card *Origin, const Card *Sorted, int N){
    for(int i = 0; i < N-1; i++){
        for (int j = i+1; j < N; j++){
            if (Origin[i].value == Origin[j].value){
                for (int a = 0; a < N-1; a++){
                    if (Origin[j].value == Sorted[a].value && Origin[j].suit == Sorted[a].suit){
                        for (int b = a+1; b < N; b++){
                            if (Origin[i].suit == Sorted[b].suit && Origin[i].value == Sorted[b].value){
                                return false;
                            }
                        }
                    }
                }
            }
            
        }
    }
    return true;
}