#include <bits/stdc++.h>
#include "avl.hpp"
using namespace std;

Avl::Avl() {
  root = NULL;
}

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

void Avl::print_partial_tree(node_t *partial_root) {
  if (partial_root == NULL) {
    cout<<".";
    return;
  }

  cout<<"(";
  print_partial_tree(partial_root->left);
  cout<<" "<<partial_root->value<<" ";
  print_partial_tree(partial_root->right);
  cout<<")";
}

void Avl::print_tree() {
  print_partial_tree(root);
}

/** search_value に一致する value を持つノードのポインタを返す。見つからなければ NULL を返す */
node_t *Avl::search(int search_value) {
  node_t *target = root;

  while (target->value != search_value && target != NULL) {
    if (target->value > search_value) {
      target = target->left;
    } else {
      target = target->right;
    }
  }

  return target;
}
