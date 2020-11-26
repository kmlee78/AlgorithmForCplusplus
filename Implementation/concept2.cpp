#include <iostream>

using namespace std;

int main(){
    string position;
    int dx, dy, tempx, tempy, count = 0;
    cin >> position;

    /*입력받은 문자열을 숫자로 바꿔
      좌표값 dx, dy에 저장해주기*/
    dx = position[0] - 96;
    dy = position[1] - '0';

    /*이동할 수 있는 방법들을 모두
      한 배열에 저장*/
    int move[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                    {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
    for(int a = 0; a < 8; a++){
        tempx = dx + move[a][0];
        tempy = dy + move[a][1];
        if(tempx > 0 && tempx < 9 && tempy > 0 && tempy < 9){
            count++;
        }
    }

    cout << count << endl;
    return 0;
}