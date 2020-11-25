#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int n;
    string plans;
    int row = 1, col = 1;
    cin >> n;
    cin.ignore();       //버퍼 비우기

    /*공백으로 구분해 값을 받기 때문에
      getline()을 사용해 string 형태인
      plans를 받고 엔터로 입력을 마친다.*/
    getline(cin, plans);    
    stringstream ss(plans);
    char direction;

    /*stringstream을 이용해 string인 plans의
      알파벳들을 하나씩 읽어낸다.*/
    while(ss >> direction){
        switch(direction){
            case 'R': col++; break;
            case 'L': col--; break;
            case 'U': row--; break;
            case 'D': row++; break; 
        }

        /*만약 좌표가 범위를 벗어나게 되면
          1씩 더하거나 빼주는 방식을 적용*/
        if(col < 1) col++;
        if(col > n) col--;
        if(row < 1) row++;
        if(row > n) row--;
    }

    cout << row << " " << col << endl;
    return 0;
}