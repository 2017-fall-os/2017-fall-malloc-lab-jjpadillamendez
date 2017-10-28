#ifndef Assert2Included
#define Assert2Included

#include <assert.h>		/* for assert */
#include <stdio.h>		/* for fprintf */

/* like assert, but prints a message if the condition is false before exit */
#define assert2(_cond_, _msg_) ((_cond_) ? 0 : \
(fprintf(stderr, "\nAssertion Failed: %s\n", _msg_), \
 fflush(stderr), assert(_cond_)))

#endif // included
