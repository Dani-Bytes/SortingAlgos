#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

// Node class for Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};