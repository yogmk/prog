# ifndef _POINT_H_

# include "Object.h"

extern const void *Point;           /* new(Point, ...) */

void draw (const void *);
void move (void *, int, int);

extern const void *PointClass;      /* adds draw */

void initPoint (void);


# define POINT_H_
# endif
