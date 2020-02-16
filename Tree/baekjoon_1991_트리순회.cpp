// runtime error
// ���� class BinaryTree ��  member variable root��
// nullptr(or 0)�� �ʱ�ȭ�� ���� ���� ��(��� ���� ���� or constructor����) 
// test case �쿬�� �¾���-> template���� �غ��� �׾ ã�� �� �־���

#include <iostream>
#include <vector>

using namespace std;


class Node {
    Node* leftChild;
    char data;
    Node* rightChild;

  public:
    Node(char c):data(c),leftChild(nullptr),rightChild(nullptr) {
    }
    //~Node isEssential
    char getData(void) {
        return data;
    }
    void setLeftChild(Node* l) {
        leftChild = l;
    }
    void setRightChild(Node* r) {
        rightChild = r;
    }
    Node* getLeftChild(void) {
        return leftChild;
    }
    Node* getRightChild(void) {
        return rightChild;
    }
};


class BinaryTree {
    Node* root = nullptr;

    vector<Node*> allNodes;

    Node* getNode(char target) {
        Node* result = nullptr;
        for(Node* node: allNodes) {
            const bool isTarget = node->getData() == target;
            if(isTarget) {
                result = node;
                break;
            }
        }
        return result;
    }
    void visit(Node* node) {
        cout << node->getData();
    }
    void preorder(Node* currentNode) {
        const bool noNode = currentNode == nullptr;
        if(noNode) {
            return;
        } else {
            visit(currentNode);
            preorder(currentNode->getLeftChild());
            preorder(currentNode->getRightChild());
        }
    }
    void inorder(Node* currentNode) {
        const bool noNode = currentNode == nullptr;
        if(noNode) {
            return;
        } else {
            inorder(currentNode->getLeftChild());
            visit(currentNode);
            inorder(currentNode->getRightChild());
        }
    }
    void postorder(Node* currentNode) {
        const bool noNode = currentNode == nullptr;
        if(noNode) {
            return;
        } else {
            postorder(currentNode->getLeftChild());
            postorder(currentNode->getRightChild());
            visit(currentNode);
        }
    }
  public:
    bool isEmpty(void) {
        return root == nullptr;
    }
    BinaryTree(char noNodeCode) {
        int nodeCount;

        cin >> nodeCount;
        for(int i=0; i<nodeCount; ++i) {
            char data,leftChild,rightChild;

            cin>>data>>leftChild>>rightChild;
            Node* node;
            const bool isLeftChild = leftChild != noNodeCode;
            const bool isRightChild = rightChild != noNodeCode;
            if(isEmpty()) {
//                cout <<"set root" <<endl;
                node = new Node(data);
                root = node;
                allNodes.push_back(node);

            } else {
                node = getNode(data);
            }
            if(isLeftChild) {
//                cout << "append left child(" << leftChild << ") to " << node->getData()<< endl;
                Node* newNode = new Node(leftChild);
                node->setLeftChild(newNode);
                allNodes.push_back(newNode);

            }
            if(isRightChild) {
//                    cout << "append right child(" << rightChild << ") to " << node->getData()<< endl;
                Node* newNode = new Node(rightChild);
                node->setRightChild(newNode);
                allNodes.push_back(newNode);

            }
        }
    }
    void inorder(void) {
        inorder(root);
        cout << endl;
    }
    void preorder(void) {
        preorder(root);
        cout << endl;
    }
    void postorder(void) {
        postorder(root);
        cout << endl;
    }
};



int main(void) {
    BinaryTree tree('.');
    tree.preorder();
    tree.inorder();
    tree.postorder();
    return 0;
}