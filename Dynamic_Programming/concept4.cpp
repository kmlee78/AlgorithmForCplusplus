#include <iostream>

using namespace std;

int money[100];
int answer[10001];

int main(){
    /*모든 answer 배열의 원소값을 매우 큰 값으로 초기화*/
    for(int i = 0; i < 10001; i++){
        answer[i] = 10001;
    }
    int n, m, x;
    cin >> n >> m;

    /*단위 화폐의 최소한의 지불 화폐 수는 1*/
    for(int a = 0; a < n; a++){
        cin >> x;
        answer[x] = 1;
        money[a] = x;
    }

    /*점화식: a[i] = (모든 a[i - x] + 1들 중 최솟값)
            x 는 처음 입력한 단위 화폐들*/
    for(int a = 1; a <= m; a++){
        for(int b = 0; b < n; b++){
            if(a-money[b] > 0){
                answer[a] = min(answer[a], answer[a-money[b]] + 1);
            }
        }
    }

    if(answer[m] == 10001) cout << "-1" << endl;
    else cout << answer[m] << endl;
    return 0;
}