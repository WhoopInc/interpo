/* xercnt.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* DECK XERCNT */
/* Subroutine */ int xercnt_(char *librar, char *subrou, char *messg, integer 
	*nerr, integer *level, integer *kontrl, ftnlen librar_len, ftnlen 
	subrou_len, ftnlen messg_len)
{
/* ***BEGIN PROLOGUE  XERCNT */
/* ***SUBSIDIARY */
/* ***PURPOSE  Allow user control over handling of errors. */
/* ***LIBRARY   SLATEC (XERROR) */
/* ***CATEGORY  R3C */
/* ***TYPE      ALL (XERCNT-A) */
/* ***KEYWORDS  ERROR, XERROR */
/* ***AUTHOR  Jones, R. E., (SNLA) */
/* ***DESCRIPTION */

/*     Abstract */
/*        Allows user control over handling of individual errors. */
/*        Just after each message is recorded, but before it is */
/*        processed any further (i.e., before it is printed or */
/*        a decision to abort is made), a call is made to XERCNT. */
/*        If the user has provided his own version of XERCNT, he */
/*        can then override the value of KONTROL used in processing */
/*        this message by redefining its value. */
/*        KONTRL may be set to any value from -2 to 2. */
/*        The meanings for KONTRL are the same as in XSETF, except */
/*        that the value of KONTRL changes only for this message. */
/*        If KONTRL is set to a value outside the range from -2 to 2, */
/*        it will be moved back into that range. */

/*     Description of Parameters */

/*      --Input-- */
/*        LIBRAR - the library that the routine is in. */
/*        SUBROU - the subroutine that XERMSG is being called from */
/*        MESSG  - the first 20 characters of the error message. */
/*        NERR   - same as in the call to XERMSG. */
/*        LEVEL  - same as in the call to XERMSG. */
/*        KONTRL - the current value of the control flag as set */
/*                 by a call to XSETF. */

/*      --Output-- */
/*        KONTRL - the new value of KONTRL.  If KONTRL is not */
/*                 defined, it will remain at its original value. */
/*                 This changed value of control affects only */
/*                 the current occurrence of the current message. */

/* ***REFERENCES  R. E. Jones and D. K. Kahaner, XERROR, the SLATEC */
/*                 Error-handling Package, SAND82-0800, Sandia */
/*                 Laboratories, 1982. */
/* ***ROUTINES CALLED  (NONE) */
/* ***REVISION HISTORY  (YYMMDD) */
/*   790801  DATE WRITTEN */
/*   861211  REVISION DATE from Version 3.2 */
/*   891214  Prologue converted to Version 4.0 format.  (BAB) */
/*   900206  Routine changed from user-callable to subsidiary.  (WRB) */
/*   900510  Changed calling sequence to include LIBRARY and SUBROUTINE */
/*           names, changed routine name from XERCTL to XERCNT.  (RWC) */
/*   920501  Reformatted the REFERENCES section.  (WRB) */
/* ***END PROLOGUE  XERCNT */
/* ***FIRST EXECUTABLE STATEMENT  XERCNT */
    return 0;
} /* xercnt_ */

