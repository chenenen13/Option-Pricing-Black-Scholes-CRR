#pragma once 

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class BinaryTree 
{
private:
    int _depth;
    vector<vector<T>> _tree;
public:

    BinaryTree() : _depth(0), _tree() {
    }

    void setDepth(int depth) {
        _depth = depth;
        _tree.resize(_depth+1);
        for (int i = 0; i <= _depth; i++) {
            _tree[i].resize(i + 1);
        }
    }

    void setNode(int level, int position, T value) {
        if (level >= 0 && level <= _depth && position >= 0 && position <= _depth) {
            _tree[level][position] = value;
        }
    }

    T getNode(int level, int position) {
        if (level >= 0 && level <= _depth && position >= 0 && position <= _depth) {
            return _tree[level][position];
        }
        return T();
    }

    void display() {
        for (int level = 0; level <= _depth; level++) {
            for (int i = 0; i <= level; i++) {
                cout << _tree[level][i] << " ";
            }
            cout << endl;
        }
    }
};