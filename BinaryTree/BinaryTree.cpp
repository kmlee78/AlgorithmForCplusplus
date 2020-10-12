#include <iostream>

using namespace std;

int number = 15;            //트리 전체 크기 15로 상정

typedef struct node* tree;
typedef struct node{
    int data;
    tree left, right;
}node;

void preorder(tree ptr){        //자신 탐색 -> 왼쪽 자식 탐색 -> 오른쪽 자식 탐색
    if(ptr)
    {
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(tree ptr){         //왼쪽 자식 탐색 -> 자신 탐색 -> 오른쪽 자식 탐색
    if(ptr)
    {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

void postorder(tree ptr){       //왼쪽 자식 탐색 -> 오른쪽 자식 탐색 -> 자신 탐색
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->right << " ";
    }
}

int main(){
    node nodes[number+1];

    for(int a = 1; a <= number; a++)        //data 입력해주기
    {
        nodes[a].data = a;
        nodes[a].left = NULL;
        nodes[a].right = NULL;
    }
    for(int b = 1; b <= number; b++)        //연결해주기
    {
        if(b%2 == 0){
            nodes[b/2].left = &nodes[b];
        }else{
            nodes[b/2].right = &nodes[b];
        }
    }

    preorder(&nodes[1]);
    inorder(&nodes[1]);
    postorder(&nodes[1]);

    return 0;
}