typedef struct _avl_node {
  int value;
  struct _avl_node *parent, *left, *right;
} avl_node_t;


class Avl {
  private:
    avl_node_t *root;
  public:
    void insert(avl_node_t insert_node);
};
