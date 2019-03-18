/*--------------------------------------------------------------------------------
K&R Exercise 7-9
Author: Gregory Pietsch

Functions like isupper can be implemented to save space or to save time. 
Explore both possibilities. 

This question is best left to an essay rather than code, so here's my take: The 
easiest way to implement the eleven is() functions in C90's version of <ctype.h> 
is via a table lookup. If UCHAR_MAX is 255, then a table would take up around 514 
8-bit bytes and still have room for five more is() functions. In modern programs, 
this is a miniscule expense of both space and time since a mere table lookup 
doesn't cost a whole lot (although space may be a priority for embedded systems). 
Additionally, since the is() functions of <ctype.h> are locale-dependent and 
therefore subject to locale-specific whims, a table could more easily be modified 
than modifying hard calculations. Consider the following three implementations of 
isupper()
--------------------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>

//--- Implementation #1
int isupper1(int c)
{
    return (c >= 'A' && c <= 'Z');
}


//--- Implementation #2
int isupper2(int c)
{
    return (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", c) != NULL);
}


//--- Implementation #3:
//--- Presumably, _UP is a power of 2 and Ctype is a table
int _Ctype[256], _UP;

int isupper3(int c)
{
    return ((_Ctype[(unsigned char)c] & _UP) != 0);
}

/*--------------------------------------------------------------------------------
Implementation #1 fails in EBCDIC and implementation #2 fails in a locale that 
adds more upperspace characters than the ones mentioned. Implementation #3, 
however, suggests that _Ctype[] can be modified to accommodate new uppercase 
characters. 
--------------------------------------------------------------------------------*/

