//
// Created by ibrahim on 2/8/23.
//

#ifndef JEFERSON_LIB_BINARYTREE_H
#define JEFERSON_LIB_BINARYTREE_H


#include <vector>
#include <iostream>

template<typename names>
struct Node {
    names value;
    int index;
};
template<typename name>
class BinaryTree {
    using valueType = name;
public:
    BinaryTree() {
        tree = std::vector<valueType>();
    }
    void insert(valueType value) {
        tree.push_back(value);



        swim(Node<valueType>{value, tree.size() - 1});
    }

    void print() {
        for (auto &i : tree) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    valueType getMax() {
        return tree[0];
    }
    valueType get(int index) {
        return tree[tree.size() - 1 - index];
    }
    valueType operator[](int n){
        return tree;
    }
private:
    std::vector<valueType> tree;
    void swim(Node<valueType> n) {
        if (n.index == 0) return;
        int parentIndex = (n.index - 1) / 2;
        if (tree[parentIndex] < n.value) {
            std::swap(tree[parentIndex], tree[n.index]);
            swim(Node<valueType>{n.value, parentIndex});
        }
    }
};


#endif //JEFERSON_LIB_BINARYTREE_H
