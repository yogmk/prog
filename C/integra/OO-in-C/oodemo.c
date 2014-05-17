
typedef struct Object* Object;
typedef struct ObjectClass* ObjectClass;

struct ObjectClass
{
        size_t __size;
        ObjectClass __super;
        ObjectClass (*destroy) (Object);
};

extern struct ObjectClass __Object;

struct Object
{
        ObjectClass __vptr;
};

int Object__IsKindOf (Object this, void *class);
Object Object_Arr_new (size_t size, short dimn);
void Object_Arr_destroy (Object obj);
void Object_NoIm (void);


typedef struct String *String; 
struct String 
{ 
   struct Object super;
   char *__buffer;
}; 

extern struct StringClass __String; 
typedef struct StringClass *StringClass; 

struct StringClass 
{ 
	struct ObjectClass super;
};

String string_new (String this, const char *str);
String string_new_from_other (String this, String other);

void string_destroy (String this);

const char *toChar (String this);

typedef struct Scalable **Scalable; 

struct Scalable 
{ 
	trdiff_t __offset;
    void (*Scale)(Object, double);
};

typedef struct Shape *Shape; 
struct Shape 
{ 
	struct Object super; 
	struct Scalable *Scalable;
    struct String name;
}; 

extern struct ShapeClass __Shape; 
typedef struct ShapeClass *ShapeClass; 

struct ShapeClass 
{ 
	struct ObjectClass super; 
	struct Scalable Scalable;
    double (*Area)(Shape);
};
    
Shape shape_new (Shape this, char *name);
void shape_destroy (Shape this);

typedef struct Rect *Rect; 
struct Rect 
{ 
	struct Shape super;
    double __w;
    double __h;
}; 

extern struct RectClass __Rect; 
typedef struct RectClass *RectClass; 

struct RectClass 
{ 
	struct ShapeClass super;
};
    
Rect rect_new (Rect this, char *name, double w, double h);
double rect_area (Rect this);
void rect_scale (Rect this, double mag);


typedef struct Circle *Circle; 
struct Circle 
{ 
	struct Shape super;
    double __r;
}; 

extern struct CircleClass __Circle; 
typedef struct CircleClass *CircleClass; 

struct CircleClass 
{ 
	struct ShapeClass super;
};
   
Circle circle_new (Circle this, char *name, double r);
double circle_area (Circle this);
void circle_scale (Circle this, double mag);

void
testShape (Shape s)
{
        ((void) ((Object__IsKindOf((Object) (s), (void*)&__Shape)) ? 
		0 : 
		(__assert_fail ("Object__IsKindOf((Object) (s), (void*)&__Shape)", "oo-demo.c", 9, __PRETTY_FUNCTION__), 0)));
        
		printf ("Shape.name = %s, Shape.Area() = %.2f\n", toChar (&s->name),
                 (*((ShapeClass)(((Object)(s))->__vptr))->Area) ((Shape) (s)));
}


void
testScalable (Scalable s)
{
        ((void) 
		((Object__IsKindOf((Object) ((Object)((char*)(s)-(*(s))->__offset)), (void*)&__Object)) ?
		0 : 
		(__assert_fail ("Object__IsKindOf((Object) ((Object)((char*)(s)-(*(s))->__offset)), (void*)&__Object)", "oo-demo.c", 20, __PRETTY_FUNCTION__), 0)));
        
		puts ("Scalable.Scale (), ");
        (*(*(s))->Scale) ((Object)((char*)(s)-(*(s))->__offset) , 2.0 );

}




int
main (void)
{
        struct Circle cir;
        Circle c;
        Rect r;
        int i;

        c = circle_new (&cir, "circle", 0.5);
        r = (Rect)Object_Arr_new(sizeof(struct Rect), 10);
        for (i=0; i < 10; i++)
          {
                char name[20];
                sprintf (name, "rectangle-%d", i);
                rect_new (&r[i], name, (double) i, 0.5);
          }


        testScalable (&c->super.Scalable);
        testShape ((Shape) c);
        for (i=0; i < 10; i++)
          {
                testScalable (&r[i].super.Scalable);
                testShape ((Shape) &r[i]);
          }


        (*((ObjectClass)(((Object)(c))->__vptr))->destroy) ((Object) (c));
        Object_Arr_destroy((Object) (r));
}
