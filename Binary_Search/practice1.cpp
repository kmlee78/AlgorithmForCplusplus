#include <iostream>
#include <vector>

using namespace std;

int counting = 0;

void search(vector<int>& array, int start, int end, int target){
    int mid = (start + end) / 2;
    if(start > end) return;
    if(array[mid] > target){
        search(array, start, mid-1, target);
    }else if(array[mid] < target){
        search(array, mid+1, end, target);
    }else{
        counting++;
        search(array, start, mid-1, target);
        search(array, mid+1, end, target);
    }
}

int main(){
    int n, x, num;
    vector<int> array;
    cin >> n >> x;
    for(int a = 0; a < n; a++){
        cin >> num;
        array.push_back(num);
    }
    search(array, 0, n-1, x);
    if(counting != 0){
        cout << counting << endl;
    }else{
        cout << counting-1 << endl;
    }
    return 0;
}
