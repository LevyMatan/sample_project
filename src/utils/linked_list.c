/**
 * @file linked_list.c
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-30
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include "linked_list.h"
#include "debug.h"

Node* list_init(void)
{
    Node* p_root = (Node*)calloc(1, sizeof(Node));
    return p_root;
}

Node* list_append(Node* p_last_elem, const uint32_t target, Vector* p_vec)
{
    Node* p_new_last_elem = (Node*)calloc(1, sizeof(Node));
    p_new_last_elem->p_next = NULL;
    p_new_last_elem->p_vec = p_vec;
    p_new_last_elem->target_sum = target;
    if (p_last_elem)
    {
        p_last_elem->p_next = p_new_last_elem;
    }
    return p_new_last_elem;
}

Node* list_search(Node* p_root, const uint32_t target)
{
    DEBUG_PRINT_FUNCTION_START();
    Node* p_cur_node = p_root;
    while (p_cur_node)
    {
        if (p_cur_node->target_sum == target)
        {
            break;
        }
        p_cur_node = p_cur_node->p_next;
    }

    DEBUG_PRINT("Found Node* = %p\n", p_cur_node);
    DEBUG_PRINT_FUNCTION_END();
    return p_cur_node;

}
Node* list_end(Node* p_root)
{
    Node* p_cur_node = p_root;
    if (p_root)
    {
        while (p_cur_node->p_next)
        {
            p_cur_node = p_cur_node->p_next;
        }
        return p_cur_node;
    }
    return NULL;
}
void list_clear(Node* p_root)
{
    if(p_root)
    {

        Node* p_cur_node = p_root;
        Node* p_next_node = p_root->p_next;
        while (p_next_node)
        {
            list_node_clear(p_cur_node);
            free(p_cur_node);
            p_cur_node = p_next_node;
            p_next_node = p_next_node->p_next;
        }
    }
}
void list_node_clear(Node* p_node_to_clear)
{
    vector_clear(p_node_to_clear->p_vec);
    p_node_to_clear->p_vec = NULL;
}
void list_node_replace(Node* p_node_to_replace, Vector* p_new_vec)
{
    DEBUG_PRINT_FUNCTION_START();
    matan_wait();
    matan_wait();
    matan_wait();
    DEBUG_PRINT("This is the new vector: %p\n", p_new_vec);
    matan_wait();
    matan_wait();
    matan_wait();
    if(p_new_vec && p_node_to_replace->p_vec)
    {
        if(p_node_to_replace->p_vec->p_vec != p_new_vec->p_vec)
        {
            DEBUG_PRINT("This is the old vector: %p\n", p_node_to_replace->p_vec->p_vec);
            matan_wait();
            matan_wait();
            matan_wait();
            vector_clear(p_node_to_replace->p_vec);
        }
        else if (p_node_to_replace->p_vec != p_new_vec)
        {
            DEBUG_PRINT("This is the old vector: %p\n", p_node_to_replace->p_vec->p_vec);
            matan_wait();
            matan_wait();
            matan_wait();
            free(p_node_to_replace->p_vec);
        }
        DEBUG_PRINT("Replacing: %p with: %p\n", p_node_to_replace->p_vec, p_new_vec);
        matan_wait();
        matan_wait();
        matan_wait();
        p_node_to_replace->p_vec = p_new_vec;

    }

    DEBUG_PRINT_FUNCTION_END();
}

Node* list_add_at_begining(Node* p_root, const uint32_t target, Vector* p_vec)
{
    Node* p_new_root = (Node*)calloc(1, sizeof(Node));
    p_new_root->p_vec = vector_deep_copy(p_vec);
    p_new_root->p_next = p_root;
    p_new_root->target_sum = target;

    return p_new_root;
}
void list_print(Node* p_root)
{
    while (p_root)
    {
        list_node_print(p_root);
        p_root = p_root->p_next;
    }

}
void list_node_print(Node* p_node)
{
        DEBUG_PRINT("Node: %p\n", p_node);
        if(p_node)
        {
            DEBUG_PRINT("Node->target_sum: %d\n", p_node->target_sum);
            if(p_node->p_vec)
            {
                DEBUG_PRINT("Node->p_ret_vec->len = %d\n", p_node->p_vec->len);
                DEBUG_PRINT_IDENT_ONLY();
                DEBUG_PRINT_VECTOR(p_node->p_vec);
                DEBUG_PRINT_NO_IDENT("\n");

            }
        }

}