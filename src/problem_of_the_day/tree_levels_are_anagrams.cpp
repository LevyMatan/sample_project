#include <vector>
#include <map>
#include <stdlib.h>

typedef struct node_s
{
    int data;
    struct node_s *left;
    struct node_s *right;
}Node;

void level_traverse(Node* node, int level, std::vector<std::map<int,int>> &tree_by_level)
{
    if(NULL == node)
    {
        return;
    }
    else
    {
        if(level < (tree_by_level.size()))
        {
            // printf("level=%d < size=%lu\n", level, tree_by_level.size());
            auto search = tree_by_level[level].find(node->data);
            if (search != tree_by_level[level].end())
            {
                tree_by_level[level][node->data]++;
            }
            else
            {
                tree_by_level[level][node->data] = 1;
            }
        }
        else
        {
            // printf("I am a new level: %d\n", level);
            std::map<int,int> *temp = new std::map<int,int>;
            (*temp)[node->data] = 1;
            // temp.push_back(node->data);
            tree_by_level.push_back(*temp);
        }

        level_traverse(node->left, level+1, tree_by_level);
        level_traverse(node->right, level+1, tree_by_level);
    }
}

bool areAnagrams(Node *root1, Node *root2)
{

    // Idea:
    // Go on one tree from left and the other from the right.
    // Add each level elements to a std::vector
    std::vector<std::map<int,int>> root1_tree_by_level;
    std::vector<std::map<int,int>> root2_tree_by_level;

    // std::vector<int> *root_vec = new std::vector<int>(1, 0);
    // tree_by_level.push_back(*root_vec);
    level_traverse(root1, 0, root1_tree_by_level);
    level_traverse(root2, 0, root2_tree_by_level);
    //print

    if(root1_tree_by_level.size() != root1_tree_by_level.size())
    {
        return false;
    }
    else
    {
        for(size_t i = 0; i < root1_tree_by_level.size(); i++)
        {
            if(root1_tree_by_level[i] != root2_tree_by_level[i])
            {
                return false;
            }
        }

    }
    return true;
}