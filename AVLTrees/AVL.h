//
// Created by Gem Gasca on 2019-11-30.
//

#ifndef PROGRAM4_AVL_H
#define PROGRAM4_AVL_H
#include <memory>
#include <string>
#include <map>

class AVL;

class AVLNode {
public:
    AVLNode();
    AVLNode(int key);                                   // constructors
    AVLNode(int key, std::weak_ptr<AVLNode> parent);
    void checkBalanceFactors(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode);
    void updateHeights(std::shared_ptr<AVLNode> currentNode);
    std::shared_ptr<AVLNode> getRight();
    std::shared_ptr<AVLNode> getLeft();
    std::shared_ptr<AVLNode> getParent();
    bool HasLeftChild() const;
    bool HasRightChild() const;
    bool HasParent(std::shared_ptr<AVLNode> currNode);
    bool IsLeaf() const;
    int getNodeHeight();
    int calculateNodeBF();
    void fixLeftHeavy(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode);
    void fixRightHeavy(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode);
    void calculateNodeHeight(int currHeight, std::shared_ptr<AVLNode> currentNode, std::vector<int>& heights);
    int findMax(std::vector<int> vect);
    void ReplaceChild(std::shared_ptr<AVLNode> v, std::shared_ptr<AVLNode> u);

    void DeleteChild(std::shared_ptr<AVLNode> v);

private:
    int key_;
    std::weak_ptr<AVLNode> parent_;
    std::shared_ptr<AVLNode> left_;
    std::shared_ptr<AVLNode> right_;
    int bf_;
    int nodeHeight;
    std::map<int, AVLNode> nodes_;      // map of all nodes in tree
    std::shared_ptr<AVLNode> root_;
    friend AVL;
}; // class AVLNode

class AVL {
public:
    AVL();
    void RR(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode);      // AVL rotation types: right right, right left, left left, left right
    void LR(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode);
    void LL(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode);
    void RL(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode);
    void Insert(int key);
    std::string JSON() const;
    size_t size() const;
    bool empty() const;
    bool Delete(int key);
    bool Find(int key) const;
    int DeleteMin();

private:
    void DeleteLeaf(std::shared_ptr<AVLNode> currentNode);
    int DeleteMin(std::shared_ptr<AVLNode> currentNode);
    std::map<int, AVLNode> nodes_;      // map of all nodes in tree
    size_t size_;
    std::shared_ptr<AVLNode> root_;
}; // class AVL

#endif //PROGRAM4_AVL_H
