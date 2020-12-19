#include <iostream>

using namespace std;

/*저장된 식량 수에 대한 정보가 들어있는 db와
  얻을 수 있는 식량의 최댓값이 들어있는 answer*/
int db[101];
int answer [101];

/*점화식: a[i] = max(a[i-1], a[i-2] + k[i])*/
int main(){
    int n, k;
    bool last = true;
    cin >> n;
    cin >> k;
    db[1] = k;
    answer[1] = db[1];
    cin >> k;
    db[2] = k;
    answer[2] = max(db[1], db[2]);
    for(int a = 3; a <= n; a++){
        cin >> k;
        db[a] = k;
        answer[a] = max(answer[a-1] , answer[a-2] + db[a]);
    }

    cout << answer[n] << endl;
    return 0;
}