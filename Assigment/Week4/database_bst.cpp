#include <iostream>
#include <cstdlib> // for malloc and exit

using namespace std;

typedef struct _Node {
    string data;
    struct _Node* leftChild;
    struct _Node* rightChild;
} Node;

Node* makeNode(string data) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        exit(1);
    }
    p->data = data;
    p->leftChild = nullptr; // S?a th�nh nullptr
    p->rightChild = nullptr; // S?a th�nh nullptr
    return p;
}

int find(Node* root, string data) {
    if (root == nullptr) return 0; // S?a th�nh nullptr
    if (root->data == data) return 1; // T�m th?y
    else if (root->data > data) return find(root->leftChild, data);
    else return find(root->rightChild, data);
}

int insert(Node*& root, string data) {
    if (root == nullptr) {
        root = makeNode(data);
        return 1; // Ch�n th�nh c�ng
    }
    if (data < root->data) {
        return insert(root->leftChild, data);
    } else if (data > root->data) {
        return insert(root->rightChild, data);
    }
    return 0; // Gi� tr? d� t?n t?i
}

int main() {
    string s;
    Node *root;
    while (true) {
        cin >> s;
        if (s == "*") break; // K?t th�c khi g?p '*'
        insert(root, s);
    }

    // X? l� c�c l?nh
    while (true) {
        cin >> s;
        if (s == "***") break; // K?t th�c khi g?p '***'
        
        if (s == "find") {
            string key;
            cin >> key;
            cout << find(root, key) << endl; // In k?t qu? t�m ki?m
        } else if (s == "insert") {
            string key;
            cin >> key;
            cout << insert(root, key) << endl; // In k?t qu? ch�n
        }
    }

    return 0;
}

