# ident "load the math library and print the cosine of 2"

# include <stdio.h>
# include <dlfcn.h>

int main(int argc, char** argv)
 {
 void* handle;
 double (*cosine)(double);
 char *err;

 handle = dlopen("libm.so", RTLD_LAZY);
 if (!handle)
  {
   fprintf(stderr, "%s\n", dlerror());
   exit (1);
  }
 
 cosine = dlsym(handle,"cos");
 if ((err = dlerror()) != NULL)
  {
  fprintf(stderr, "%s\n", err);
  exit (1);
  }

 /* all is well, invoke the function */

 printf("%f\n", (*cosine)(2.0));
 dlclose(handle);
 return 0;
 }
