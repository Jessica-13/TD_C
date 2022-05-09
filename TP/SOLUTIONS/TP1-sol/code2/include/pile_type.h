#ifndef __PILE_TYPE_H_
#define __PILE_TYPE_H_

struct elem_model {
    int elem;
    struct elem_model* suivant;
};
typedef struct elem_model ELEMPILE;
typedef ELEMPILE* PILE;

#endif