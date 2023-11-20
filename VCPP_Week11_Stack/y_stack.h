#pragma once // include �Ҷ� ��ø�Ǵ� ���� �ѹ��� ���Եǵ��� ������Ų��.


// ��� Ŭ����
class Node {
public:
    int data;     // ������ ����
    Node* next;   // ���� ��� ������

    Node(int data) : data(data), next(nullptr) {} // ������
};

// ���� Ŭ����
class y_Stack {
private:
    Node* top; // ������ �� �� ������

public:
    y_Stack();    // ������
    ~y_Stack();   // �Ҹ���

    void push(int data); // ���ÿ� �����͸� �߰�
    int pop();  // ���ÿ��� �����͸� �����ϰ� ��ȯ
    int peek(); // ������ �� �� �����͸� ��ȸ

    bool isEmpty(); // ������ ��� �ִ���
};