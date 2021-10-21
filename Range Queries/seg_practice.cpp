#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define pint pair<int, int>
#define us unordered_set

// Q: For a given query i x, find the greatest j such that j < i and a[j] < x. 

int base = 1;
vector<int> tree;
void init(vector<int> a) {
    int n = a.size();
    // find the least power of 2 greater than or equal to n
    while(base < n) {
        base *= 2;
    }

    // resize tree
    tree.resize(2 * base);
    // fill first N leaves with values from the input
    for(int i = 0; i < n; ++i) {
        tree[base+i] = a[i];
    }
    // update all other nodes
    for(int i = base - 1; i >= 1; --i) {
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
}

// changing value at index i to x
void change(int i, int x) {
    tree[base+i] = x;
    for(int j = (base + i) / 2; j >= 1; j /= 2) {
        tree[j] = min(tree[2*j], tree[2*j+1]);
    }
}

int find_first_before(int i, int x) {
    if(tree[base+i] < x) {
        return i;
    }
    // we don't include node == 1 as we may confuse root as a right node 
    // (can't find left sibling of root node)s
    for(int node = base + i; node > 1; node /= 2) {
        // if I am right child
        if(node % 2 == 1) {
            // if left sibling meets requirement
            if(tree[node-1] < x) {
                node--;
                // start descending from this right sibling
                while(node < base) { // while not a leaf
                    // prioritize right child
                    if(tree[2*node + 1] < x) {
                        node = 2 * node + 1;
                    }
                    // we go left if not
                    else {
                        node = 2 * node;
                    }
                }
                return node - base; // to get index [0, n-1]
            }
        }
    }
    return -1;
}

