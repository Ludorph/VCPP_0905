#include "y_Stack.h"
#include <iostream>
using namespace std;

// 생성자
y_Stack::y_Stack() {
    top = nullptr; // 초기화 시 top은 null
}


// 소멸자
y_Stack::~y_Stack() {
    while (!isEmpty()) {
        pop(); // isempty가 아니라면 모든 요소 제거
    }
}


// 데이터를 추가
void y_Stack::push(int data) {
    Node* newNode = new Node(data); // 새 노드 생성
    newNode->next = top; // 새 노드 next 현재 top으로 설정
    top = newNode; // 새 노드를 새로운 top으로 설정
}

// 데이터를 제거하고 반환
int y_Stack::pop() {
    if (isEmpty()) {
        cout << "y_Stack Underflow" << endl;
        return -1;
    }
    else {
        Node* temp = top; // 현재 top 노드 임시 저장
        top = top->next; // top을 다음 노드로 이동
        int poppedData = temp->data; // 제거될 데이터 저장
        delete temp; // 노드 메모리 해제
        return poppedData; // 제거된 데이터 반환
    }
}

// 맨 위 데이터를 조회
int y_Stack::peek() {
    if (isEmpty()) {
        cout << "y_Stack is Empty" << endl;
        return -1;
    }
    else {
        return top->data; // top 데이터 반환
    }
}

// 비어 있는지 확인
bool y_Stack::isEmpty() {
    return top == nullptr; // top이 null이면 스택은 비어있음
}