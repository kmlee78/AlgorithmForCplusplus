#include <iostream>

using namespace std;

int answer [1001];

/*점화식: a[i] = a[i-1] + a[i-2]*2*/
int main(){
    int n;
    cin >> n;
    answer[1] = 1;
    answer[2] = 3;
    for(int a = 3; a <= n; a++){
        answer[a] = (answer[a-1] + answer[a-2] * 2) % 796796;
    }

    cout << answer[n] << endl;
    return 0;
}