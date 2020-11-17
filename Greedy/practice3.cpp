#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    int array[2] = {0, 0}, length = s.length();
    int status = s[0] - '0';
    array[status]++;
    for(int a = 1; a < length; a++){
        if(s[a] - '0' != status){
            array[s[a]-'0']++;
            status = s[a] - '0';
        }
    }
    cout << min(array[0], array[1]) << endl;
    return 0;
}