// runtime error
// 원인 class BinaryTree 의  member variable root를
// nullptr(or 0)로 초기화를 하지 않은 것(멤버 변수 선언 or constructor에서) 
// test case 우연히 맞았음-> template없이 해보니 죽어서 찾을 수 있었다
/*
    memory: 1988KB
    time: 0ms
    lang: C++11
    length: 3618B
*/



#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Node{
    Node<T>* leftChild;
    T data;
    Node<T>* rightChild;
    
public:
    Node(const T& d):data(d),leftChild(nullptr),rightChild(nullptr){
    }
    //~Node isEssential
    const T& getData(void){
        return data;
    }
    void setLeftChild(Node<T>* l){
        leftChild = l;
    }
    void setRightChild(Node<T>* r){
        rightChild = r;
    }
    Node<T>* getLeftChild(void){
        return leftChild;
    }
    Node<T>* getRightChild(void){
        return rightChild;
    }
};

template<typename T>
class BinaryTree{
    Node<T>* root;
    
    vector<Node<T>*> allNodes;
    
    Node<T>* getNode(const T& target){
        Node<T>* result = 0;
        for(Node<T>* node: allNodes){
            const bool isTarget = node->getData() == target;
            if(isTarget){
                result = node;
                break;
            }
        }
        return result;
    }
    void visit(Node<T>* node){
        cout << node->getData();
    }
    void preorder(Node<T>* currentNode){
        const bool noNode = currentNode == nullptr;
        if(noNode){
            return;
        }
        else{
            visit(currentNode);
            preorder(currentNode->getLeftChild());
            preorder(currentNode->getRightChild());
        }
    }
    void inorder(Node<T>* currentNode){
        const bool noNode = currentNode == nullptr;
        if(noNode){
            return;
        }
        else{
            inorder(currentNode->getLeftChild());
            visit(currentNode);
            inorder(currentNode->getRightChild());
        }        
    }
    void postorder(Node<T>* currentNode){
        const bool noNode = currentNode == nullptr;
        if(noNode){
            return;
        }
        else{
            postorder(currentNode->getLeftChild());
            postorder(currentNode->getRightChild());
            visit(currentNode);
        }
    }
public:
    bool isEmpty(void){
        return root == nullptr;
    }
    BinaryTree(const T& noNodeCode):root(nullptr){
        int nodeCount;
        
        cin >> nodeCount;
        for(int i=0;i<nodeCount;++i){
            T data,leftChild,rightChild;
            
            cin>>data>>leftChild>>rightChild;
            Node<T>* node;
            const bool isLeftChild = leftChild != noNodeCode;
            const bool isRightChild = rightChild != noNodeCode;
            if(isEmpty()){
                node = new Node<T>(data);
                root = node;
                allNodes.push_back(node);
            }
            else{
                node = getNode(data);
            }
            if(isLeftChild){
                Node<T>* newNode = new Node<T>(leftChild);
                node->setLeftChild(newNode);
                allNodes.push_back(newNode);
            }
            if(isRightChild){
                Node<T>* newNode = new Node<T>(rightChild);
                node->setRightChild(newNode);
                allNodes.push_back(newNode);
            }
        }
    }
    void inorder(void){
        inorder(root);
        cout << endl;
    }
    void preorder(void){
        preorder(root);
        cout << endl;
    }
    void postorder(void){
        postorder(root);
        cout << endl;
    }
};



int main(void)
{
    BinaryTree<char> tree('.');
    tree.preorder();
    tree.inorder();
    tree.postorder();
    return 0;
}