#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> board;

bool dfs(int a, int b){
    bool yeah;
    /*해당 방문 지역이 범위를 벗어나면 빠른 손절*/
    if(a < 0 || a >= board.size() || b < 0 || b >= board[0].length()) return false;

    /*해당 방문 지역의 값이 0이면 1로 바꿔주고 탐색 시작.
      그리고 인접한 모든 요소들도 0인 값이 있다면 1로 바꿔줌.
      그리고 결국에는 true를 리턴하게 된다. 
      만약 처음부터 1이라면 바로 false 리턴*/
    if(board[a][b] == '0'){
        board[a][b] = '1';
        yeah = dfs(a+1, b);
        yeah = dfs(a-1, b);
        yeah = dfs(a, b+1);
        yeah = dfs(a, b-1);
        return true;
    }
    return false;
}

int main(){
    int n, m, counting = 0;
    cin >> n >> m;
    string ice;
    for(int a = 0; a < n; a++){
        cin >> ice;
        board.push_back(ice);
    }

    /*board 내의 모든 요소들을 순회하며 탐색 시작*/
    for(int a = 0; a < n; a++){
        for(int b = 0; b < m; b++){
            if(dfs(a, b) == true)
                counting++;
        }
    }

    cout << counting << endl;
    return 0;
}
