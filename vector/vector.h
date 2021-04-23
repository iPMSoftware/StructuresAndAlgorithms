#ifndef IPM_VECTOR_H
#define IPM_VECTOR_H

/*-----------------------------------------------------------------------------
 * Copyright (C) 2015 by iPM Software
 *
 * All rights reserved.  No part of this software may be reproduced,
 * transmitted, transcribed, stored in a retrieval system, or translated
 * into any language or computer language, in any form or by any means,
 * electronic, mechanical, magnetic, optical, chemical, manual or otherwise,
 * without the prior written permission of iPM Software
 *---------------------------------------------------------------------------*/

/**
 * @file     ipm_vector.h
 *
 * @author   PAWEŁ MIRGOS
 *
 * @brief    Header for simple (int)vector implementation
 *
 */

/*-----------------------------------------------------------------------------
 * Includes
 *---------------------------------------------------------------------------*/

/* Include from the same module */

/* Include from other module */

/* Include from system modules */
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif

/*-----------------------------------------------------------------------------
 * Forward declarations
 *---------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * Preprocessor constants
 *---------------------------------------------------------------------------*/

/* use define only if there is no other choice ! */

 /*-----------------------------------------------------------------------------
 * Macros
 *---------------------------------------------------------------------------*/

/* use only if necessary, use inline functions instead */

/*-----------------------------------------------------------------------------
 * Constants
 *---------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * Data types
 *---------------------------------------------------------------------------*/

typedef struct ipm_vector* ipm_vector_ptr;

/*-----------------------------------------------------------------------------
 * Exported variables
 *---------------------------------------------------------------------------*/

 /* use it only if necessary */

/*-----------------------------------------------------------------------------
 * Exported functions
 *---------------------------------------------------------------------------*/
ipm_vector_ptr ipm_vector_init(int size);

void ipm_vector_push_back(const ipm_vector_ptr vec_ptr, int data);

// Element access
int ipm_vector_get_at(const ipm_vector_ptr vec_ptr, int pos);
int ipm_vector_front(const ipm_vector_ptr vec_ptr);
int ipm_vector_back(const ipm_vector_ptr vec_ptr);

//Capacity
bool ipm_vector_empty(const ipm_vector_ptr vec_ptr);
int ipm_vector_size(const ipm_vector_ptr vec_ptr);
void ipm_vector_reserve(const ipm_vector_ptr vec_ptr, int new_capacity);



void ipm_vector_print(const ipm_vector_ptr vec_ptr);




#ifdef __cplusplus
}
#endif
#endif /* IPM_VECTOR_H */

