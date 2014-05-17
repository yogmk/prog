/*
 *----------------------------------------------------------------------
 * Object.h: Header file defining root base class 'Object'.
 *           Also defines -
 *                          Macros for defining classes,
 *                          Macros for definign Interfaces,
 *                          implementing classes,
 *                          invoking virtual functions (late binding),
 *                          handling objects on the 'heap',
 *                          and a simple RTTI.
 *----------------------------------------------------------------------
 */


# ifndef __OBJECT__

# include <stddef.h>                   /* for *_t types & NULL */
# include <stdlib.h>                   
# include <string.h>                   
 
 /**
  *  Abstract base class 'Object'
  */

typedef struct Object* Object;
typedef struct ObjectClass* ObjectClass;

struct ObjectClass
  {
  	size_t        __size;   			/* size of object instance */
	ObjectClass   __super;              /* superclass descriptor pointer (see typedef) */
	ObjectClass (*destroy) (Object);    /* function pointer for destructor */
  };

extern struct ObjectClass __Object;

struct Object
  {
  	ObjectClass    __vptr;              /* private virtual pointer */
  };


 /**
  *  Macros for Protected Constructors & Destructors
  */

# define Object_new(this)       { (this)->__vptr = &__Object; }
# define Object_destroy(this)   {}

/**
 *  test for type compatibility, use through macro only
 */

int Object__IsKindOf (Object this, void *class);
	
/**
 *  handle Objects on heap, use through macros only
 */

Object Object_Arr_new (size_t size, short dimn);
void Object_Arr_destroy (Object obj);


/**
 *  Dummy implementation for abstract methods
 */

void Object_NoImpl (void);

/**
 *  Set of macros for declaring classes
 */

# define CLASS(CX, SX)\
	typedef struct CX *CX;\
	struct CX\
	  {\
	  struct SX super;
# define IMPLEMENTS(IX)	struct IX *IX
# define VTABLE(CX, SX)\
    };\
	extern struct CX##Class  __##CX;\
	typedef struct CX##Class *CX##Class;\
	struct CX##Class\
	  {\
	  struct SX##Class super;
# define FUNCTIONS };
# define END_CLASS	


/**
 *  Set of macros for defining Interfaces
 */

# define INTERFACE(IX) typedef struct IX **IX;\
       struct IX\
	      {\
		    ptrdiff_t  __offset;
# define END_INTERFACE };

# define EXTENDS(IX) struct IX IX


/**
 *  Macros for defining VTABLEs and binding virtual functions
 */

# define BEGIN_VTABLE(CX, SX) \
     struct CX##Class __##CX;\
     static void CX##Class_new(CX t)\
	   {\
	      CX##Class vptr=&__##CX;\
		  memcpy(vptr, ((Object)t)->__vptr, sizeof(struct SX##Class));\
		  ((ObjectClass)vptr)->__size = sizeof(struct CX);
# define VFUNCTION(CX, MX)  ((CX##Class)vptr)->MX
# define IFUNCTION(IX, MX)\
     if (vptr->IX.__offset == 0)\
	 	 vptr->IX.__offset = (char*)&t->IX-(char*)t;\
	 vptr->IX.MX
# define END_VTABLE\
     ((ObjectClass)vptr)->__super=((Object)t)->__vptr;\
	 }

/**
 *  Macros needed in constructors
 */

# define VHOOK(OX, CX)\
  {\
    if(((ObjectClass)&__##CX)->__size == 0)\
	   CX##Class_new(OX);\
	   ((Object)(OX))->__vptr=(void*)&__##CX;\
  }
# define IHOOK(OX, CX, IX) (OX)->IX=&__##CX.IX

/**
 *  Macro for invoking virtual class functions
 *  and interface functions.
 */

# define  VCALL(OX, CX, MX)\
  (*((CX##Class)(((Object)(OX))->__vptr))->MX) ((CX) (OX)
# define ICALL(IPX, MX)  (*(*(IPX))->MX) (I_TO_OBJ(IPX)
# define END_CALL )

/**
 *  Macros for handling objects on the heap
 */

# define ALLOC(CX) (CX)malloc(sizeof(struct CX))
# define FREE(OX)\
         {\
		   VCALL(OX, Object, destroy)END_CALL;\
		   free((void*)(OX));\
		 }
# define ALLOC_ARR(CX, DX)\
         (CX)Object_Arr_new(sizeof(struct CX), DX)

# define FREE_ARR(OX) Object_Arr_destroy((Object) (OX))


/**
 * Macros for RTTI
 */

# define IS_RUNTIME_CLASS(OX, CX)\
         Object__IsKindOf((Object) (OX), (void*)&__##CX)

# define I_TO_OBJ(IPX)  (Object)((char*)(IPX)-(*(IPX))->__offset)

# define __OBJECT__
# endif

         
