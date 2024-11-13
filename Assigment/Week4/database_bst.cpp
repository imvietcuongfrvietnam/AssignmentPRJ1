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
    p->leftChild = nullptr; // S?a thành nullptr
    p->rightChild = nullptr; // S?a thành nullptr
    return p;
}

int find(Node* root, string data) {
    if (root == nullptr) return 0; // S?a thành nullptr
    if (root->data == data) return 1; // Tìm th?y
    else if (root->data > data) return find(root->leftChild, data);
    else return find(root->rightChild, data);
}

int insert(Node*& root, string data) {
    if (root == nullptr) {
        root = makeNode(data);
        return 1; // Chèn thành công
    }
    if (data < root->data) {
        return insert(root->leftChild, data);
    } else if (data > root->data) {
        return insert(root->rightChild, data);
    }
    return 0; // Giá tr? dã t?n t?i
}

int main() {
    string s;
    Node *root;
    while (true) {
        cin >> s;
        if (s == "*") break; // K?t thúc khi g?p '*'
        insert(root, s);
    }

    // X? lý các l?nh
    while (true) {
        cin >> s;
        if (s == "***") break; // K?t thúc khi g?p '***'
        
        if (s == "find") {
            string key;
            cin >> key;
            cout << find(root, key) << endl; // In k?t qu? tìm ki?m
        } else if (s == "insert") {
            string key;
            cin >> key;
            cout << insert(root, key) << endl; // In k?t qu? chèn
        }
    }

    return 0;
}

