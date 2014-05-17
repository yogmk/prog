/* a function to check whether the difference in 2 Pixel values is close enough */

/*
 * Source: comp.lang.c FAQ 14.5
 */

typedef float Pixel;

# define Abs(x) ((x) < 0 ? -(x) :(x))
# define Max(a,b) ((a) > (b) ? (a) : (b))

float rltdiff (const Pixel a, const float b)
{
  Pixel a_ = a;
  float b_ = b;

  b_ = Max(a_, b_);

  return b_ == 0.0 ? 0.0 : Abs(a - b);
}
