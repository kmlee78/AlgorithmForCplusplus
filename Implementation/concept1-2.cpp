#include <iostream>
#include <string>

using namespace std;

int main (){
    int n, count = 0;
    cin >> n;

    /*모든 경우를 삼중 for문으로 돌려
      '3'이라는 문자가 존재할 때마다
      count를 하나씩 늘려준다.*/
    for(int a = 0; a <= n; a++){
        for(int b = 0; b < 60; b++){
            for(int c = 0; c < 60; c++){
                int i = to_string(a).find('3');
                int j = to_string(b).find('3');
                int k = to_string(c).find('3');
                if(i == 0 || i == 1 || j == 1 || j == 0 || k == 0 || k == 1)
                    count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}