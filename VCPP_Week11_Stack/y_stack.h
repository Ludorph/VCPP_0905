#pragma once // include 할때 중첩되는 것을 한번만 포함되도로 지정시킨다.


// 노드 클래스
class Node {
public:
    int data;     // 데이터 저장
    Node* next;   // 다음 노드 포인터

    Node(int data) : data(data), next(nullptr) {} // 생성자
};

// 스택 클래스
class y_Stack {
private:
    Node* top; // 스택의 맨 위 포인터

public:
    y_Stack();    // 생성자
    ~y_Stack();   // 소멸자

    void push(int data); // 스택에 데이터를 추가
    int pop();  // 스택에서 데이터를 제거하고 반환
    int peek(); // 스택의 맨 위 데이터를 조회

    bool isEmpty(); // 스택이 비어 있는지
};