/*
    memory: 1984KB
    time:   0ms
    lang:   C++11

*/ 
 

#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

template<typename T>
class Node {
    T data;
    list<Node<T>*> children;

  public:
    Node(const T& d):data(d),children(0) {
    }
    ~Node() {
        for(Node<T>*child: children)
            delete child;
    }
    T& getData(void) {
        return data;
    }
    list<Node<T>*>& getChildren(void) {
        return children;
    }
    void appendChild(Node<T>* child) {
        children.push_back(child);
    }
    void deleteChild(Node<T>* child) {
        children.remove(child);

    }
};

template<typename T>
class Tree {
    Node<T>* root;

  public:
    Tree(void):root(nullptr) {
        int  nodeCount;
        vector<T> parents(0);
        cin >> nodeCount;
        vector<Node<T>*> allNodes(nodeCount);
        for(int i=0; i<nodeCount; ++i) {
            Node<T>* currentNode = new Node<T>(i);
            allNodes[i] = currentNode;
        }
        for(int i=0; i<nodeCount; ++i) {
            T parent;
            cin >> parent;
            const bool isRoot = parent == -1;
            if(isRoot) {
                root = allNodes[i];
            } else {
                allNodes[parent] -> appendChild(allNodes[i]);
            }
        }
    }
    void erase(const T& data) {
        const bool noTree = root==nullptr;
        if(noTree)
            return;

        const bool isRootDeleted = root->getData() == data;
        if(isRootDeleted) {
            delete root;
//            cout << boolalpha <<(root == nullptr);
            root = nullptr;
            return;
        }
        queue<Node<T>*> searchedNodes;
        searchedNodes.push(root);
        while(!searchedNodes.empty()) {
            Node<T>* currentNode = searchedNodes.front();
            searchedNodes.pop();
            for(Node<T>* child: currentNode->getChildren()) {
                const bool found = data == child->getData();
                if(found) {
                    currentNode->deleteChild(child);
                    return;
                }
                searchedNodes.push(child);
            }
        }
    }
    int countLeaf(void) {
        const bool noTree = root==nullptr;
        if(noTree)
            return 0;
            
        int leafCount = 0;
        queue<Node<T>*> checkedNodes;
        checkedNodes.push(root);
        while(!checkedNodes.empty()) {
            Node<T>* currentNode = checkedNodes.front();
            checkedNodes.pop();
            const bool isLeaf = currentNode->getChildren().empty();
            if(isLeaf) {
                ++leafCount;
            } else {
                for(Node<T>* child: currentNode->getChildren()) {
                    checkedNodes.push(child);
                }
            }
        }
        return leafCount;
    }
};

int main(void) {
    Tree<int> tree;
    int nodeNumber;
    cin >> nodeNumber;
    tree.erase(nodeNumber);
    cout << tree.countLeaf();
    return 0;
}