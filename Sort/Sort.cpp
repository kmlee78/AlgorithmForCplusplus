#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*3개의 elements를 가진 데이터를 저장
상품명 - 중요도 - 재고량 순
1. 중요도 순으로 데이터 정렬
2. 중요도가 같으면 재고량 순으로 정렬
3. 재고량도 같으면 상품명 사전순으로 정렬*/

bool comp(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b){
    if(a.second.first == b.second.first){
        if(a.second.second == b.second.second)
            return a.first < b.first;
        else return a.second.second < b.second.second;
    }else
    {
        return a.second.first < b.second.first; 
    }
}

int main(){
    vector<pair<string, pair<int, int>>> data;
    data.push_back(pair<string, pair<int, int>>("Banana", pair<int, int>(2, 1000)));
    data.push_back(pair<string, pair<int, int>>("Apple", pair<int, int>(3, 4000)));
    data.push_back(pair<string, pair<int, int>>("Kiwi", pair<int, int>(4, 1000)));
    data.push_back(pair<string, pair<int, int>>("Peach", pair<int, int>(1, 2000)));
    data.push_back(pair<string, pair<int, int>>("Orange", pair<int, int>(3, 5000)));
    data.push_back(pair<string, pair<int, int>>("Pinapple", pair<int, int>(5, 1000)));
    data.push_back(pair<string, pair<int, int>>("Cherry", pair<int, int>(2, 1000)));
    data.push_back(pair<string, pair<int, int>>("Melon", pair<int, int>(4, 3000)));
    data.push_back(pair<string, pair<int, int>>("Grape", pair<int, int>(2, 2000)));
    data.push_back(pair<string, pair<int, int>>("Tomato", pair<int, int>(1, 5000)));

    sort(data.begin(), data.end(), comp);
    vector<pair<string, pair<int, int>>>::iterator it;
    for(it = data.begin(); it != data.end(); it++){
        cout << it->first << endl;
    }   
    //순서대로 Peach Tomato Banana Cherry Grape Apple Orange Kiwi Melon Pineapple
}