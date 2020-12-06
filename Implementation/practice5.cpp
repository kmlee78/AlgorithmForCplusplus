#include <iostream>
#include <vector>

using namespace std;

/*timeline이라는 배열을 만들어 시간에 따른
  방향 변환 정보를 담아준다.*/
int timeline[10001];

int main(){
    int n, k, row_apple, col_apple, l, x;
    char c;
    /*row와 col 배열은 뱀을 동서남북 중 한 방향으로
      진행시키기 위한 방향 정보를 담은 배열이다. 나중에
      유용하게 쓸 예정.*/
    int row[4] = {0, 1, 0, -1},
        col[4] = {1, 0, -1, 0},
        row_head = 1,
        col_head = 1,
        counting = 0,
        direction = 0;

    cin >> n >> k;
    /*실제 크기 보다 가장자리에 1씩 크기를 
      확장한 벡터 board를 만들어 준다. 
      snake 벡터는 뱀 머리부터 꼬리까지 존재하는
      모든 부분을 pair로 담아준 벡터이다.*/
    vector<vector<int>> board(n+2, vector<int>(n+2, 0));
    vector<pair<int, int>> snake;

    /*사과가 있는 곳의 값은 1,
      그 나머지는 0으로 한다.*/
    for(int i = 0; i < k; i++){
        cin >> row_apple >> col_apple;
        board[row_apple][col_apple] = 1;
    }
    cin >> l;
    for(int i = 0; i < l; i++){
        cin >> x >> c;
        if(c == 'D') timeline[x] = 1;
        else timeline[x] = 3;
    }
    snake.push_back(pair<int, int>(row_head, col_head));

    while(true){
        /*시간이 1씩 흐를때 마다 counting도 1씩 늘고,
          timeline의 인덱싱도 하나씩 는다. 오른쪽으로 회전할때는
          row 배열과 col 배열 내 인덱싱이 1씩 늘고, 왼쪽으로 회전할때는
          인덱싱이 3씩 는다. 4로 나눈 나머지를 구해 인덱싱을 하면 원하는
          방향으로 뱀을 진행시킬 수 있다.*/
        direction += timeline[counting];
        direction = direction % 4;
        row_head += row[direction];
        col_head += col[direction];
        counting++;
        
        pair<int, int> temp = make_pair(row_head, col_head);
        /*벽과 부딪힐 때*/
        if(row_head == 0 || row_head == n+1 || col_head == 0 || col_head == n+1 ){
            break;
        }
        /*뱀이 자기 자신과 부딪히는지 탐색*/
        bool check = false;
        for(int j = 0; j < snake.size(); j++){
            if(snake[j].first == temp.first && snake[j].second == temp.second)
                check = true;
        }
        if(check) break;

        /*도달한 곳에 사과가 있다면 사과가 있던 자리를 0
          으로 바꿔주고 만약 사과가 없다면 뱀의 꼬리 부분을
          지워준다.*/
        if(board[row_head][col_head] == 1){
            board[row_head][col_head] = 0;
        }else{
            snake.erase(snake.begin());
        }
        /*새롭게 도달한 뱀의 머리의 좌표를 snake 벡터에 추가한다.*/
        snake.push_back(temp);
    }

    cout << counting << endl;
    return 0;
}
