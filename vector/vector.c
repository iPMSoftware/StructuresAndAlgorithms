/*-----------------------------------------------------------------------------
 * Copyright (C) 2021 by iPM Software
 *
 * All rights reserved.  No part of this software may be reproduced,
 * transmitted, transcribed, stored in a retrieval system, or translated
 * into any language or computer language, in any form or by any means,
 * electronic, mechanical, magnetic, optical, chemical, manual or otherwise,
 * without the prior written permission of iPM Software
 *---------------------------------------------------------------------------*/

/**
 * @file     vector.c
 *
 * @author   PAWEŁ MIRGOS
 *
 * @brief    Vector implementation functions
 *
 */

/*-----------------------------------------------------------------------------
 * Includes
 *----------------------------------------------------------------------------*/

/* Include corresponding header file, in alphabetical order */
#include "vector.h"

/* Include other header from module, in alphabetical order */

/* Include from other module, in alphabetical order */

/* Include from system modules, in alphabetical order */
/* It's good to explain why to include certain header */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------
 * Preprocessor constants
 *---------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * Data types
 *---------------------------------------------------------------------------*/
 struct  ipm_vector{
    int capacity_;
    int size_;
    int* buff_;
} ;

/*-----------------------------------------------------------------------------
 * Variables
 *---------------------------------------------------------------------------*/

/* local buff */

/* shared state */

/*-----------------------------------------------------------------------------
 * Constants
 *---------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * Internal functions declarations
 *---------------------------------------------------------------------------*/

static void internal_realloc_buffer(const ipm_vector_ptr vec_ptr, int new_size) {
    int* temp = (int*)malloc(sizeof(int)*new_size);
        for(int i=0;i<vec_ptr->size_;i++) {
            temp[i] = vec_ptr->buff_[i];
        }
        free(vec_ptr->buff_);
        vec_ptr->buff_ = temp;
        vec_ptr->capacity_ = new_size;
}

/*-----------------------------------------------------------------------------
 * Functions definitions
 *---------------------------------------------------------------------------*/

ipm_vector_ptr ipm_vector_init(int count) {
    struct ipm_vector* v;
    v = malloc(sizeof(struct ipm_vector) * count);
    v->capacity_ = count;
    v->size_ = 0;
    v->buff_ = malloc(count * sizeof(int));
    return v;
}

//-----------------------------------------------------------------------------

void ipm_vector_push_back(const ipm_vector_ptr vec_ptr, int data) {
    if(vec_ptr->size_ == vec_ptr->capacity_) {
        internal_realloc_buffer(vec_ptr,vec_ptr->capacity_*2);
    }
    vec_ptr->buff_[vec_ptr->size_++] = data;
}

//-----------------------------------------------------------------------------

int ipm_vector_get_at(const ipm_vector_ptr vec_ptr, int pos) {
    if(pos > vec_ptr->size_) {
        fprintf(stderr, "Accessing vector out of range\n");
       exit( EXIT_FAILURE );
    }
    return vec_ptr->buff_[pos];
}

//-----------------------------------------------------------------------------

int ipm_vector_front(const ipm_vector_ptr vec_ptr) {
    if(vec_ptr->size_ == 0) {
        fprintf(stderr, "Accessing vector out of range\n");
       exit( EXIT_FAILURE );
    }
    return vec_ptr->buff_[0];
}

//-----------------------------------------------------------------------------

int ipm_vector_back(const ipm_vector_ptr vec_ptr) {
    if(vec_ptr->size_ == 0) {
        fprintf(stderr, "Accessing vector out of range\n");
       exit( EXIT_FAILURE );
    }
    return vec_ptr->buff_[vec_ptr->size_-1];
}

//-----------------------------------------------------------------------------

bool ipm_vector_empty(const ipm_vector_ptr vec_ptr) {
    return 0 == ipm_vector_size(vec_ptr);
}

//-----------------------------------------------------------------------------

int ipm_vector_size(const ipm_vector_ptr vec_ptr) {
    return vec_ptr->size_;
}

//-----------------------------------------------------------------------------

void ipm_vector_reserve(const ipm_vector_ptr vec_ptr, int new_capacity) {
    if(new_capacity <= vec_ptr->capacity_)
        return;
    internal_realloc_buffer(vec_ptr,new_capacity);
}

//-----------------------------------------------------------------------------

void ipm_vector_shrink_to_fit(const ipm_vector_ptr vec_ptr) {
    if(vec_ptr->size_ == vec_ptr->capacity_)
        return;
    internal_realloc_buffer(vec_ptr,vec_ptr->size_);
}

//-----------------------------------------------------------------------------

void ipm_vector_print(const ipm_vector_ptr vec_ptr) {
    for(int i=0;i<(vec_ptr->size_);i++) {
        printf("%d %d\n",i+1,vec_ptr->buff_[i]);
    }
}

//-----------------------------------------------------------------------------