#include <iostream>

using namespace std;

int main(){
   int n, m, row, col, dir, answer = 1;
   cin >> n >> m >> row >> col >> dir;
   int land[n][m];
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
        dir = (dir + 3) % 4;
        row += dx[dir];
        col += dy[dir];

        if(land[row][col] == 0 && row < n && col < m){
            land[row][col] = 2;
            answer++;
            turn = 0;
        }else{
            row -= dx[dir];
            col -= dy[dir];
            turn++;
        }

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