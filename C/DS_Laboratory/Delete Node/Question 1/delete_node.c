#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    BST tree;
    init(&tree);
    int ch, ele, x, pos;
    do
    {
        printf("\nChoose an Option:\n1-Insertion\n2-Inorder Display\n3-Deletion\n4-exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter an element:\n");
            scanf("%d", &ele);
            insert(&tree, ele);
            break;
        case 2:
            inorder(tree.root);
            break;
        case 3:
            printf("enter the element to be deleted:\n");
            scanf("%d", &ele);
            tree.root = delete (tree.root, ele);
            printf("%d has been deleted\n ", ele);
            inorder(tree.root);
            break;
        }
    } while (ch != 4);
    return 0;
}

