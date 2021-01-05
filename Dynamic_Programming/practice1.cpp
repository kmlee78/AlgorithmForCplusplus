#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, n, m;
    int best;
    vector<int> answer;
    cin >> t;
    for(int a = 0; a < t; a++){
        cin >> n >> m;

        /*금광의 정보를 담은 배열 mine과 각 칸 까지 올 때
          얻을 수 있는 금의 최댓값의 정보를 담은 배열 gold를
          만들어준다. 일단 gold의 첫 열은 mine의 첫 열과 같다*/
        int mine[n][m];
        int gold[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mine[i][j];
                if(j == 0){
                    gold[i][j] = mine[i][j];
                }
            }
        }

        /*그리고 두번째 열 부터 gold에 들어갈 값을 구해준다.
          각 칸에 들어갈 값은 해당 위치의 mine값과 왼쪽 위, 왼쪽,
          왼쪽 아래에 있는 gold값을 더한 것 중 가장 큰 값이 된다*/
        for(int j = 1; j < m; j++){
            for(int i = 0; i < n; i++){
                gold[i][j] = mine[i][j] +gold[i][j-1];
                if(i-1 >= 0){
                    gold[i][j] = max(gold[i][j], mine[i][j] + gold[i-1][j-1]);
                }
                if(i+1 <= n-1){
                    gold[i][j] = max(gold[i][j], mine[i][j] + gold[i+1][j-1]);
                }
            }
        }

        /*이렇게 모든 gold의 칸을 구하게 되면 맨 마지막 열의
          원소들 중 가장 큰 값을 찾아 벡터 안에 넣어준다*/
        best = gold[0][m-1];
        for(int a = 1; a < n; a++){
            best = max(best, gold[a][m-1]);
        }
        answer.push_back(best);
    }

    for(int a = 0; a < answer.size(); a++){
        cout << answer[a] << endl;
    }
    return 0;
}