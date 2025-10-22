#include "bt_utils.h"

void test_bfs() {
    printf("** test_bfs() **\n");

    User u1 = { "Bobbie", "Draper" };
    User u2 = { "Amos", "Burton" };
    User u3 = { "Josephus", "Miller" };

    // Create binary tree
    BTNode *root = add_btnode(u1);

    root->left = add_btnode(u2);
    root->right = add_btnode(u3);

    bfs(root);

    // release_tree(root);
}

// void test_dfs() {
//     printf("** test_dfs() **\n");
//     // Create binary tree
//     BTNode *root = add_btnode(15);

//     root->left = add_btnode(10);
//     root->left->left = add_btnode(5);
//     root->left->right = add_btnode(12);
//     root->right = add_btnode(25);
//     root->right->left = add_btnode(20);
//     root->right->right = add_btnode(30);

//     printf("PREORDER\n");
//     dfs(root, PREORDER);
//     printf("INORDER\n");
//     dfs(root, INORDER);
//     printf("POSTORDER\n");
//     dfs(root, POSTORDER);

//     release_tree(root);
// }

void test_insert() {
    printf("** test_insert() **\n");
    BTNode *root = NULL;

    User *users = load_users("names.txt");

    for (int i = 0; i < 14; i++) {
        insert(&root, users[i]);
    }

    bfs(root);

    // release_tree(root);
}

// void test_search() {
//     printf("** test_search() **\n");
//     BTNode *root = NULL;

//     insert(&root, 10);
//     insert(&root, 8);
//     insert(&root, 4);
//     insert(&root, 13);
//     insert(&root, 1);
//     insert(&root, 21);

//     BTNode *s1 = search(root, 4);
//     BTNode *s2 = search(root, 3);

//     if (s1) {
//         printf("Found 4\n");
//     } else {
//         printf("Cannot find 4\n");
//     }

//     if (s2) {
//         printf("Found 3\n");
//     } else {
//         printf("Cannot find 3\n");
//     }

//     release_tree(root);
// }

int main() {
    // Test bfs
    test_bfs();

    // Test dfs
    // test_dfs();

    // Test insert
    test_insert();

    // Test search
    // test_search();

    return 0;
}
