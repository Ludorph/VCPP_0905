#include "y_Stack.h"
#include <iostream>
using namespace std;

// ������
y_Stack::y_Stack() {
    top = nullptr; // �ʱ�ȭ �� top�� null
}


// �Ҹ���
y_Stack::~y_Stack() {
    while (!isEmpty()) {
        pop(); // isempty�� �ƴ϶�� ��� ��� ����
    }
}


// �����͸� �߰�
void y_Stack::push(int data) {
    Node* newNode = new Node(data); // �� ��� ����
    newNode->next = top; // �� ��� next ���� top���� ����
    top = newNode; // �� ��带 ���ο� top���� ����
}

// �����͸� �����ϰ� ��ȯ
int y_Stack::pop() {
    if (isEmpty()) {
        cout << "y_Stack Underflow" << endl;
        return -1;
    }
    else {
        Node* temp = top; // ���� top ��� �ӽ� ����
        top = top->next; // top�� ���� ���� �̵�
        int poppedData = temp->data; // ���ŵ� ������ ����
        delete temp; // ��� �޸� ����
        return poppedData; // ���ŵ� ������ ��ȯ
    }
}

// �� �� �����͸� ��ȸ
int y_Stack::peek() {
    if (isEmpty()) {
        cout << "y_Stack is Empty" << endl;
        return -1;
    }
    else {
        return top->data; // top ������ ��ȯ
    }
}

// ��� �ִ��� Ȯ��
bool y_Stack::isEmpty() {
    return top == nullptr; // top�� null�̸� ������ �������
}