#include <vector>
#include <string>

using namespace std;

vector<vector<int>> solution(int n, bool horizontal) {

    /*answer벡터로 표현된 배열의 각 행과 열에 자유롭게 접근할 수 
    있도록 미리 크기를 n*n으로 설정해둔다*/
    vector<vector<int>> answer(n, vector<int>(n));
    int row = 0, col = 0, time = 1, count = 1, dir = 1;
    while(row < n && col < n){

        /*로봇이 대각선으로 이동할 때 사용되는 반복문이다. 시간을 나타내는 time은
        2씩 증가하고 방향을 나타내는 변수 dir에 따라 행과 열이 바뀌면서 answer벡터에
        time값을 삽입한다. 단, 첫 time값은 로봇의 수직이동 직후임을 감안하여 1을 빼준다*/
        for (time -= 1; row >= 0 && row < n && col >= 0 && col < n ;){   
            answer[row][col] = time;
            row += dir;
            col -= dir;
            time += 2;
        }

        /*로봇의 이동방향이 왼쪽 아래일 때*/
        if (dir > 0){
            /*로봇이 전체 정사각형 배열의 절반을 넘었을 때*/
            if (count >= n){
                row -= 1;
                col += 2;
            }else{
                col += 1;
            }
        /*로봇의 이동방향이 오른쪽 위일 때*/
        }else{
            if (count >= n){
                row += 2;
                col -= 1;
            }else{
                row += 1;
            }
        }
            count++;
            dir *= -1;
        }

    /*위 코드는 처음에 로봇이 오른쪽으로 가지 않았을 경우를 가정하고
    계산한 것이므로 만약 horizontal이 true라면 transposed matrix를
    return 해 준다*/
    if(horizontal){
        vector<vector<int>> temp(answer);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                answer[i][j] = temp[j][i];
            }
        }
    }
    return answer;
}