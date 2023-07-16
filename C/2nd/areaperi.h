#include<math.h>

#define TRI_PERI(a, b, c) (a + b + c)
#define SP(a, b, c) ( (a + b + c) / 2.0 )
#define TRI_AREA(a, b, c) ( sqrt( SP(a,b,c) * \
                                 ( SP(a,b,c) - a ) *\
                                  (SP(a,b,c) - b) * \
                                  (SP(a,b,c) - c)) )

#define SQR_PERI(s) (4 * s)
#define SQR_AREA(s) (s * s)

#define C_PERI(r) (2 * M_PI * r)
#define C_AREA(r) (M_PI * r * r)
