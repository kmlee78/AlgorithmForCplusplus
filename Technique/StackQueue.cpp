#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    /*stack 구현*/
    stack<int> s;
    s.push(7);
    s.pop();        //맨 위에 있는거 pop
    s.push(6);
    s.push(5);
    s.push(4);
    while(!s.empty())       //stack 빌 때까지 출력
    {
        cout << s.top() << " ";
        s.pop();        //4 5 6 
    }
    cout << endl;

    
    /*queue 구현*/
    queue<int> q;
    q.push(3);
    q.pop();        //맨 앞에 있는거 pop
    q.push(4);
    q.push(5);
    q.push(6);
    while(!q.empty())       //queue 빌 때까지 출력
    {
        cout << q.front() << " ";
        q.pop();        //4 5 6 
    }
    
    
    /*priority_queue 구현
      우선순위 큐는 새로운 요소가 삽입될 때 마다
      우선순위에 맞춰 내림차순으로 정렬되는 큐이다.*/
    priority_queue<int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(7);
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();           //7 5 1
    }
}