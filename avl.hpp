typedef struct _node {
  int value;
  struct _node *parent, *left, *right;
  char status;
} node_t;


class Avl {
  private:
    node_t *root;
    node_t *create_new_node(int value);
    void print_partial_tree(node_t *partial_root);
  public:
    Avl();
    void insert_node(int new_value);
    void delete_node(int delete_value);
    node_t *search(int search_value);
    void print_tree();
};
