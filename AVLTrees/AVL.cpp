//
// Created by Gem Gasca on 2019-11-30.
//

#include "AVL.h"
#include <cassert>
#include <iostream>
#include <string>
#include <queue>
#include "json.hpp"

AVLNode::AVLNode():
    key_(0),
    parent_(std::weak_ptr<AVLNode>()),
    left_(nullptr),
    right_(nullptr),
    nodeHeight(0),
    bf_(0) {}

AVLNode::AVLNode(int key) :
    key_(key),
    parent_(std::weak_ptr<AVLNode>()),
    left_(nullptr),
    right_(nullptr),
    nodeHeight(0),
    bf_(0) {}

AVLNode::AVLNode(int key, std::weak_ptr<AVLNode> parent) :
  key_(key),
  parent_(parent),
  left_(nullptr),
  right_(nullptr),
  nodeHeight(0),
  bf_(0) {}

AVL::AVL() :
    root_(nullptr),
    size_(0) {}

bool AVLNode::IsLeaf() const {
    return left_ == nullptr && right_ == nullptr;
}

bool AVLNode::HasLeftChild() const {
    return left_ != nullptr;
}

bool AVLNode::HasRightChild() const {
    return right_ != nullptr;
}

bool AVLNode::HasParent(std::shared_ptr<AVLNode> currNode) {
    std::weak_ptr<AVLNode>& parent = currNode->parent_;     // converts weak ptr parent into shared ptr
    std::shared_ptr<AVLNode> newParent = parent.lock();
    if (newParent != nullptr){
        return true;
    }
    return false;
}

std::shared_ptr<AVLNode> AVLNode::getParent(){
    std::weak_ptr<AVLNode>& parent = this->parent_;
    std::shared_ptr<AVLNode> newParent = parent.lock();
    return newParent;
}

std::shared_ptr<AVLNode> AVLNode::getRight(){
    return right_;
}

std::shared_ptr<AVLNode> AVLNode::getLeft(){
    return left_;
}

int AVLNode::getNodeHeight(){
    return nodeHeight;
}

int AVLNode::calculateNodeBF(){
    if (this->HasRightChild() && this->HasLeftChild()) {        // has both right and left children
        return (this->getRight()->getNodeHeight() - this->getLeft()->getNodeHeight());
    }
    else if (this->HasRightChild()){        // has only right child
        return (1 + this->getRight()->getNodeHeight());
    }
    else if (this->HasLeftChild()){         // has only left child
        return -(1 + this->getLeft()->getNodeHeight());
    }
    else {          // is leaf
        return 0;
    }
}

// node inserted, check for inbalances
void AVLNode::checkBalanceFactors(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode) {
    int bf = problemNode->calculateNodeBF();    // calculates bf_
    nodes_[problemNode->key_].bf_ = bf;

    //  Starting from currentNode, travel up and find the first unbalanced node.
    //  Let problemNode be the first unbalanced node, problemNodeChild be the
    //  child of problemNode that comes on the path from currentNode to problemNode
    //  and problemNodeGrandChild be the grandchild of problemNode that comes on the path from currentNode to problemNode.

    if (bf == 1 || bf == 0 || bf == -1){        // balanced node so far, keep percolating up tree
        if (problemNode->HasParent(problemNode)) {      // if has parent, go to it
            std::shared_ptr<AVLNode> parent = problemNode->getParent();
            checkBalanceFactors(problemNodeChild, problemNode, parent);
        }
        else{
            return;     // at root
        }
    }

    if (bf < -1){      // not balanced at current, currentNode = problemNode
        std::shared_ptr<AVLNode> parent = problemNode->getParent();
        fixLeftHeavy(problemNodeChild, problemNode, parent);
    }
    else if (bf > 1){
        std::shared_ptr<AVLNode> parent = problemNode->getParent();
        fixRightHeavy(problemNodeChild, problemNode, parent);
    }

}

void AVL::Insert(int key) {
    AVLNode node = AVLNode(key);
    nodes_[key] = node;         // adds node to map of nodes (key->node)
    nodes_[key].bf_ = 0;
    nodes_[key].nodeHeight = 0;

    if (root_ == nullptr) {
        root_ = std::make_shared<AVLNode>(key);
        size_++;
        return;
    }

    std::shared_ptr<AVLNode> currentNode = root_, lastNode = nullptr;
    while (currentNode != nullptr) {
        lastNode = currentNode;
        currentNode = (key < currentNode->key_) ?
                      currentNode->left_ : currentNode->right_;
    }
    if (key < lastNode->key_) {
        lastNode->left_ = std::make_shared<AVLNode>(key, lastNode);
    } else {
        lastNode->right_ = std::make_shared<AVLNode>(key, lastNode);
    }

    size_++;        // increments size
    currentNode->updateHeights(root_);              // calculates height of every node after adding new one

    std::shared_ptr<AVLNode> problemNodeGrandchild = nullptr;
    std::shared_ptr<AVLNode> problemNodeChild = nullptr;
    std::shared_ptr<AVLNode> problemNode = currentNode;
    currentNode->checkBalanceFactors(problemNodeGrandchild, problemNodeChild, problemNode);        // makes sure tree is balanced
}

size_t AVL::size() const {
    return size_;
}

void AVLNode::calculateNodeHeight(int currHeight, std::shared_ptr<AVLNode> currentNode, std::vector<int>& heights){
    // appends all heights to height array
    if (currentNode->HasLeftChild()){           // if has left, go left, increment height
        currHeight++;
        calculateNodeHeight(currHeight, currentNode->left_, heights);
    }
    else if (currentNode->HasRightChild()){      // if only has right, go right, increment height
        currHeight++;
        calculateNodeHeight(currHeight, currentNode->right_, heights);
    }
    else{            // if can't go right or left, is leaf, done adding heights, add height to vect
        heights.push_back(currHeight);
        return;
    }
}

void AVLNode::updateHeights(std::shared_ptr<AVLNode> currentNode) {
    if (currentNode == nullptr){
        return;
    }

    if (currentNode->HasLeftChild()) {           // if has left, go left
        updateHeights(currentNode->left_);
    } else if (currentNode->HasRightChild()) {      // if it has no left but has right, go right
        updateHeights(currentNode->right_);
    } else {            // is leaf, return to parent
        return;
    }

    int currHeight = 0;
    std::vector<int> heights;               // all distances from this node to its leaves
    currentNode->calculateNodeHeight(currHeight, currentNode, heights);      // makes vector of all heights (node -> each leaf)

    nodes_[currentNode->key_].nodeHeight = findMax(heights);        // makes node height max distance to leaf
}

int AVLNode::findMax(std::vector<int> vect){
    int max = vect[0];
    for (int i = 1; i < vect.size(); i++){
        if (vect[i] > max) {
            max = vect[i];
        }
    }
    return max;
}

std::string AVL::JSON() const {
    nlohmann::json result;
    std::queue< std::shared_ptr<AVLNode> > nodes;
    if (root_ != nullptr) {
        result["root"] = root_->key_;
        nodes.push(root_);
        while (!nodes.empty()) {
            auto v = nodes.front();
            nodes.pop();
            std::string key = std::to_string(v->key_);
            if (v->left_ != nullptr) {
                result[key]["left"] = v->left_->key_;
                nodes.push(v->left_);
            }
            if (v->right_ != nullptr) {
                result[key]["right"] = v->right_->key_;
                nodes.push(v->right_);
            }
            if (v->parent_.lock() != nullptr) {
                result[key]["parent"] = v->parent_.lock()->key_;
            } else {
                result[key]["root"] = true;
            }
        }
    }
    result["size"] = size_;
    return result.dump(2) + "\n";
}

void AVLNode::fixLeftHeavy(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode){

}

void AVLNode::fixRightHeavy(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode){

}


void AVL::LL(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode){
    problemNodeChild = problemNode->left_;
    problemNode->left_ = problemNodeChild->right_;
    problemNodeChild->right_ = problemNode;
}

void AVL::RR(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode){
    // current node is unbalanced
    // problemNodeGrandchild = D, problemNodeChild = B, problemNode = A


}

void AVL::LR(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode){

}

void AVL::RL(std::shared_ptr<AVLNode>& problemNodeGrandchild, std::shared_ptr<AVLNode>& problemNodeChild, std::shared_ptr<AVLNode>& problemNode){

}




// UNUSED FUNCTIONS

bool AVL::empty() const {
    return size_ == 0;
}

bool AVL::Find(int key) const {
    std::shared_ptr<AVLNode> currentNode = root_;
    while (currentNode != nullptr) {
        if (currentNode->key_ == key) {
            return true;
        }
        currentNode = (key < currentNode->key_) ?
                      currentNode->left_ : currentNode->right_;
    }
    return false;
}

void AVLNode::DeleteChild(std::shared_ptr<AVLNode> v) {
    if (left_ == v) {
        left_ = nullptr;
    } else if (right_ == v) {
        right_ = nullptr;
    } else {
        std::cerr << "AVLNode::DeleteChild Error: non-child passed as argument\n";
        exit(EXIT_FAILURE);
    }
}

void AVLNode::ReplaceChild(std::shared_ptr<AVLNode> v, std::shared_ptr<AVLNode> u) {
    if (left_ == u || right_ == u) {
        std::cerr << "AVLNode::ReplaceChild Error: child passed as replacement\n";
    }
    if (left_ == v) {
        left_ = u;
        u->parent_ = v->parent_;
    } else if (right_ == v) {
        right_ = u;
        u->parent_ = v->parent_;
    } else {
        std::cerr << "AVLNode::ReplaceChild Error: non-child passed as argument\n";
        exit(EXIT_FAILURE);
    }
}

bool AVL::Delete(int key) {
    std::shared_ptr<AVLNode> currentNode = root_;
    while (currentNode != nullptr) {
        if (currentNode->key_ == key) {
            if (currentNode->IsLeaf()) {
                DeleteLeaf(currentNode);
            } else if (currentNode->left_ == nullptr) {
                assert(currentNode->right_ != nullptr);
                std::shared_ptr<AVLNode> parent = currentNode->parent_.lock();
                parent->ReplaceChild(currentNode, currentNode->right_);
                size_--; assert(size_ >= 0);
            } else if (currentNode->right_ == nullptr) {
                assert(currentNode->left_ != nullptr);
                std::shared_ptr<AVLNode> parent = currentNode->parent_.lock();
                parent->ReplaceChild(currentNode, currentNode->left_);
                size_--; assert(size_ >= 0);
            } else {
                currentNode->key_ = DeleteMin(currentNode);
            }
        }
        currentNode = (key < currentNode->key_) ?
                      currentNode->left_ : currentNode->right_;
    }
    return false;
}

int AVL::DeleteMin() {
    return DeleteMin(root_);
}


void AVL::DeleteLeaf(std::shared_ptr<AVLNode> currentNode) {
    std::shared_ptr<AVLNode> parent = currentNode->parent_.lock();
    if (parent == nullptr) {
        // Delete root
        root_ = nullptr;
        size_--; assert(size_ == 0);
    } else {
        if (parent->right_ == currentNode) {
            parent->right_ = nullptr;
        } else if (parent->left_ == currentNode) {
            parent->left_ = nullptr;
        } else {
            std::cerr << "AVL::DeleteLeaf Error: inconsistent state\n";
        }
        size_--; assert(size_ >= 0);
    }
}

int AVL::DeleteMin(std::shared_ptr<AVLNode> currentNode) {
    std::shared_ptr<AVLNode> lastNode = nullptr;
    while (currentNode != nullptr) {
        lastNode = currentNode;
        currentNode = currentNode->left_;
    }
    int result = lastNode->key_;
    std::shared_ptr<AVLNode> parent = lastNode->parent_.lock();
    if (parent == nullptr) {
        // lastNode is root
        if (lastNode->right_ != nullptr) {
            root_ = lastNode->right_;
            lastNode->right_->parent_.reset();
        } else {
            root_ = nullptr;
        }
    } else {
        // lastNode under the root
        if (lastNode->right_ != nullptr) {
            parent->left_ = lastNode->right_;
            lastNode->right_->parent_ = parent;
        } else {
            parent->left_ = nullptr;
        }
    }
    size_--; assert(size_ >= 0);
    return result;
}

// CONVERT PARENT TO SHARED PTR
//std::weak_ptr<AVLNode>& parent = lastNode->parent_;     // converts weak ptr parent into shared ptr
//lastNode = parent.lock();