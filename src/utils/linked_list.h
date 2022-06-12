#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdint.h>
#include <stdio.h>

#include "vector.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct node_target_and_vector_s{

    uint32_t target_sum;
    Vector* p_vec;
    struct node_target_and_vector_s *p_next;
};

typedef struct node_target_and_vector_s Node;


Node* list_append(Node* p_last_elem, const uint32_t target, Vector* p_vec);
Node* list_add_at_begining(Node* p_root, const uint32_t target, Vector* p_vec);

Node* list_search(Node* p_root, const uint32_t target);
void list_node_replace(Node* p_node_to_replace, Vector* p_new_vec);
Node* list_end(Node* p_root);
void list_clear(Node* p_root);
void list_node_clear(Node* p_node_to_clear);
void list_node_print(Node* p_node);

void list_print(Node* p_root);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__LINKED_LIST_H__
