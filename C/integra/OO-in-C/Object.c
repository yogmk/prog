# ident "@(#)Object.c : implementation file for Object class and functions."

# include "Object.h"
# include <assert.h>

/** implementation of Object class */

struct ObjectClass __Object = {
       sizeof (struct Object),              /* size of Object atributes */
       NULL,                                /* no superclass            */
       (void (*)(Object)) Object_NoImpl     /* pur virtual destrucor    */
  };


int
Object__IsKindOf (Object this, void *class)
{
    ObjectClass c;
    for (c = this->__vptr; c; c = c->__super)
    {
         if (c == class)
              return 1;
    }
    return 0;
}


Object
Object_Arr_new (size_t size, short dim)
{
    short *a = NULL;
    if ((a = malloc (sizeof(short)+ dim*size)) == NULL)
        return NULL;
    else
    {
         *a = dim;                  /* store array dimension */
         return ((Object) (a+1));   /* return the location of 1st object */
    }
}



void
Object_Arr_destroy (Object pobj)
{
    char *p;                        /* location og an object */
    short i;                        /* index into the array  */
    short *a = (short*)pobj - 1;    /* start of allocated memory */
    size_t s = ((ObjectClass)pobj->__vptr)->__size;

    for (i=0, p=(char*)pobj; i < *a; i++, p+=s)
    {
        VCALL(p, Object, destroy)END_CALL;
    }
    free ((void*)a);
}


void
Object_NoImpl (void)
{
    assert(0);                       /* breaks the execution */
}


