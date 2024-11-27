#include "unity.h"
#include "rb_utils.h"

void setUp(void) {}

void tearDown(void) {}

void test_rotate_left() {
    RBNode *alpha = calloc(1, sizeof(RBNode));
    RBNode *beta = calloc(1, sizeof(RBNode));
    RBNode *gamma = calloc(1, sizeof(RBNode));
    RBNode *x = calloc(1, sizeof(RBNode));
    RBNode *y = calloc(1, sizeof(RBNode));
    RBTree tree = { x };

    beta->p = y;
    gamma->p = y;
    y->left = beta;
    y->right = gamma;
    y->p = x;
    x->right = y;
    alpha->p = x;
    x->left = alpha;

    rotate_left(&tree, x);

    // x tests
    TEST_ASSERT_EQUAL_PTR(x, alpha->p);
    TEST_ASSERT_EQUAL_PTR(x, beta->p);
    TEST_ASSERT_EQUAL_PTR(alpha, x->left);
    TEST_ASSERT_EQUAL_PTR(beta, x->right);
    TEST_ASSERT_EQUAL_PTR(y, x->p);

    // y tests
    TEST_ASSERT_EQUAL_PTR(y, gamma->p);
    TEST_ASSERT_EQUAL_PTR(gamma, y->right);
    TEST_ASSERT_EQUAL_PTR(x, y->left);
    TEST_ASSERT_NULL(y->p);

    free_tree(y);
}

void test_rotate_right() {
    RBNode *alpha = calloc(1, sizeof(RBNode));
    RBNode *beta = calloc(1, sizeof(RBNode));
    RBNode *gamma = calloc(1, sizeof(RBNode));
    RBNode *x = calloc(1, sizeof(RBNode));
    RBNode *y = calloc(1, sizeof(RBNode));
    RBTree tree = { y };

    alpha->p = x;
    beta->p = x;
    x->left = alpha;
    x->right = beta;
    x->p = y;
    y->right = gamma;
    gamma->p = y;
    y->left = x;

    rotate_right(&tree, y);

    // x tests
    TEST_ASSERT_EQUAL_PTR(x, alpha->p);
    TEST_ASSERT_EQUAL_PTR(alpha, x->left);
    TEST_ASSERT_EQUAL_PTR(y, x->right);
    TEST_ASSERT_EQUAL_PTR(x, y->p);
    TEST_ASSERT_NULL(x->p);

    // y tests
    TEST_ASSERT_EQUAL_PTR(y, beta->p);
    TEST_ASSERT_EQUAL_PTR(y, gamma->p);
    TEST_ASSERT_EQUAL_PTR(gamma, y->right);
    TEST_ASSERT_EQUAL_PTR(beta, y->left);

    free_tree(x);
}

void test_insert_case1_left() {
    RBNode *n1 = add_rbnode(7);
    RBNode *n2 = add_rbnode(5);
    RBNode *n3 = add_rbnode(10);
    RBNode *z = add_rbnode(6);
    RBTree tree = { n1 };

    n1->color = BLACK;

    // Establish relationships
    n1->left = n2;
    n1->right = n3;
    n2->p = n1;
    n3->p = n1;

    insert(&tree, z);

    // Test
    TEST_ASSERT_EQUAL_PTR(n2, z->p);
    TEST_ASSERT_EQUAL_PTR(z, n2->right);
    TEST_ASSERT_EQUAL_CHAR(BLACK, n1->color);
    TEST_ASSERT_EQUAL_CHAR(BLACK, n2->color);
    TEST_ASSERT_EQUAL_CHAR(BLACK, n3->color);
    TEST_ASSERT_EQUAL_CHAR(RED, z->color);

    free_tree(n1);
}

void test_insert_case2_left() {
    RBNode *n1 = add_rbnode(7);
    RBNode *n2 = add_rbnode(5);
    RBNode *n3 = add_rbnode(10);
    RBNode *n4 = add_rbnode(4);
    RBNode *n5 = add_rbnode(6);
    RBNode *n6 = add_rbnode(2);
    RBNode *z = add_rbnode(3);
    RBTree tree = { n1 };

    n1->color = BLACK;

    // Establish relationships
    n1->left = n2;
    n1->right = n3;
    n2->p = n1;
    n3->p = n1;

    n2->left = n4;
    n4->p = n2;
    n2->right = n5;
    n5->p = n2;

    n6->p = n4;
    n4->left = n6;

    // colorings
    n3->color = BLACK;
    n4->color = BLACK;
    n5->color = BLACK;

    insert(&tree, z);

    // Test relationships
    TEST_ASSERT_EQUAL_PTR(n6, z->left);
    TEST_ASSERT_EQUAL_PTR(z, n6->p);
    TEST_ASSERT_EQUAL_PTR(n2, z->p);
    TEST_ASSERT_EQUAL_PTR(z, n2->left);
    TEST_ASSERT_EQUAL_PTR(n4, z->right);
    TEST_ASSERT_EQUAL_PTR(z, n4->p);

    // Test colorings
    TEST_ASSERT_EQUAL_CHAR(BLACK, n1->color);
    TEST_ASSERT_EQUAL_CHAR(RED, n2->color);
    TEST_ASSERT_EQUAL_CHAR(RED, n4->color);
    TEST_ASSERT_EQUAL_CHAR(RED, n6->color);
    TEST_ASSERT_EQUAL_CHAR(BLACK, z->color);

    free_tree(n1);
}

void test_insert_case3_left() {
    RBNode *n1 = add_rbnode(7);
    RBNode *n2 = add_rbnode(5);
    RBNode *n3 = add_rbnode(10);
    RBNode *n4 = add_rbnode(3);
    RBNode *n5 = add_rbnode(6);
    RBNode *n6 = add_rbnode(2);
    RBNode *z = add_rbnode(1);
    RBTree tree = { n1 };

    n1->color = BLACK;

    // Establish relationships
    n1->left = n2;
    n1->right = n3;
    n2->p = n1;
    n3->p = n1;

    n2->left = n4;
    n4->p = n2;
    n2->right = n5;
    n5->p = n2;

    n6->p = n4;
    n4->left = n6;

    // colorings
    n3->color = BLACK;
    n4->color = BLACK;
    n5->color = BLACK;

    insert(&tree, z);

    print_tree(&tree);

    // Test relationships
    TEST_ASSERT_EQUAL_PTR(n6, n2->left);
    TEST_ASSERT_EQUAL_PTR(n2, n6->p);
    TEST_ASSERT_EQUAL_PTR(z, n6->left);
    TEST_ASSERT_EQUAL_PTR(n6, z->p);
    TEST_ASSERT_EQUAL_PTR(n4, n6->right);
    TEST_ASSERT_EQUAL_PTR(n6, n4->p);

    // Test colorings
    TEST_ASSERT_EQUAL_CHAR(BLACK, n1->color);
    TEST_ASSERT_EQUAL_CHAR(RED, n2->color);
    TEST_ASSERT_EQUAL_CHAR(RED, n4->color);
    TEST_ASSERT_EQUAL_CHAR(BLACK, n6->color);
    TEST_ASSERT_EQUAL_CHAR(RED, z->color);

    free_tree(n1);
}

void test_delete_case1() {
    int numbers[] = { 10, 4, 20, 2, 6, 15, 25, 1, 3, 12, 17, 22, 30 };

    RBTree tree = { 0 };

    for (int i = 0; i < 13; i++) {
        insert(&tree, add_rbnode(numbers[i]));
    }
    print_tree(&tree);

    delete_node(&tree, tree.root->left->right);

    print_tree(&tree);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_rotate_left);
    RUN_TEST(test_rotate_right);
    RUN_TEST(test_insert_case1_left);
    RUN_TEST(test_insert_case2_left);
    RUN_TEST(test_insert_case3_left);
    RUN_TEST(test_delete_case1);
    return UNITY_END();
}