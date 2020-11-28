#include <iostream>

using namespace std;

int main(){
   int n, m, row, col, dir, answer = 1;
   cin >> n >> m >> row >> col >> dir;
   int land[n][m];

   /*<이 부분 매우 중요!>
     2차원 공간의 방향벡터 활용은 이렇게 
     한 배열 안에 그 요소를 미리 저장해 두어
     나중에 사용하도록 한다.*/
   int dx[4] = {-1, 0, 1, 0},
        dy[4] = {0, 1, 0, -1};

   for(int a = 0; a < n; a++){
        for(int b = 0; b < m; b++){
            cin >> land[a][b];
        }
   }
   int turn = 0;
   land[row][col] = 2;
   while(1){

       /*이 과정을 통해 방향을
         북->서->남->동 순 으로
         회전할 수 있게 한다.*/
        dir = (dir + 3) % 4;
        row += dx[dir];
        col += dy[dir];

        /*회전해서 도달한 곳이 0 이고,
          배열을 벗어나지 않는다면 가본 땅으로
          표시하고 turn을 초기화 한다.
          그게 아니라면 다시 원래대로 돌아온다.*/
        if(land[row][col] == 0 && row < n && col < m){
            land[row][col] = 2;
            answer++;
            turn = 0;
        }else{
            row -= dx[dir];
            col -= dy[dir];
            turn++;
        }

        /*4번을 회전해도 아무 곳도 가지 못한다면
          뒤로 이동하고, 뒤로 이동한 곳이
          육지이고 배열을 벗어나지 않는다면 
          계속 반복문을 수행하도록 한다.
          그렇지 않을 경우에는 반복문을 빠져나온다.*/
        if(turn == 4){
            row -= dx[dir];
            col -= dy[dir];
            if(land[row][col] == 2 && row < n && col < m){
                turn = 0;
            }else{
                break;
            }
        }
   }

   cout << answer << endl;
   return 0;
}