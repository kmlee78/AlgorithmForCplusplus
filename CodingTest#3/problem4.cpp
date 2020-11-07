#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> board) {
    int answer = 0;

    /*숫자 1부터 n*n의 숫자까지의 좌표값을 담아줄 배열
    arr을 만들어 준다. arr[0][0]과 arr[0][1]은 처음 시작점을
    나타내주기 위해 0,0 으로 설정한다*/
    int arr[n*n+1][2];
    arr[0][0] = 0;
    arr[0][1] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[board[i][j]][0] = i;
            arr[board[i][j]][1] = j;
        }
    }
    
    /*arr배열을 훑으며 1부터 n*n까지의 숫자들을 순회한다.
    숫자 a에서 a+1까지 이동하는데 생기는 총 입력 횟수는
    (해당 열에서 열로 가는 최단거리)+(해당 행에서 행으로 가는 최단거리)+1 이다*/
    for(int a = 0; a < n*n; a++){
        answer += min(abs(arr[a][0]-arr[a+1][0]), n - max(arr[a][0], arr[a+1][0]) + min(arr[a][0], arr[a+1][0]));
        answer += min(abs(arr[a][1]-arr[a+1][1]), n - max(arr[a][1], arr[a+1][1]) + min(arr[a][1], arr[a+1][1]));
        answer += 1;
    }
    return answer;
}