#include <iostream>

using namespace std;

int db[30001];

/*점화식: a[i] = min(a[i-1], a[i/2], a[i/3], a[i/5]) + 1 */
int main(){
    int x;
    cin >> x;
    db[1] = 0;
    for(int a = 2; a <= x; a++){
        db[a] = db[a-1] + 1;
        if(a % 2 == 0) db[a] = min(db[a], db[a/2]+1);
        if(a % 3 == 0) db[a] = min(db[a], db[a/3]+1);
        if(a % 5 == 0) db[a] = min(db[a], db[a/5]+1);
    }

    cout << db[x] << endl;
    return 0;
}