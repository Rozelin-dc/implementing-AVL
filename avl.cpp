#include <bits/stdc++.h>
#include "avl.hpp"
using namespace std;

node_t *Avl::create_new_node(int value) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (new_node == NULL) {
    cerr<<"malloc error!"<<endl;
    exit(1);
  }

  new_node->value = value;
  new_node->status = 'E';
  new_node->parent = NULL;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

Avl::Avl() {
  root = NULL;
}
