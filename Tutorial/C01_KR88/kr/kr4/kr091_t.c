/*--------------------------------------------------------------------------------
Authors: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, July 2007

Remark: This program is not really a test program, but it should at least help you 
to undestand the conditional inclusion in C.

Remark 2: In good practice, one include only header files ".h" in a program, see 
chap. 4.5 !!! But for simplicity reason, we include here directly the needed ".c" 
file containing the printsys() function.
--------------------------------------------------------------------------------*/

// Check if SYSTEM is already defined. If not, define it.
#ifndef SYSTEM
    #define LINUX 0	
    #define OSX   1
    #define MSDOS 2 
    #define VISTA 3
    #define default 1000

    #define SYSTEM OSX /* Try out the values LINUX, OSX, MSDOS, VISTA, default  */
#endif

// Choose the adequate file to be included 
// (each of these files contains a specific function printsys)
#if SYSTEM == LINUX
    #define HDR "kr91_cond_incl/linux.c"
#elif SYSTEM == OSX
    #define HDR "kr91_cond_incl/osx.c"
#elif SYSTEM == MSDOS
    #define HDR "kr91_cond_incl/msdos.c"
#elif SYSTEM == VISTA
    #define HDR "kr91_cond_incl/vista.c"
#else 
    #define HDR "kr91_cond_incl/default.c"
#endif

#include HDR

main(){
  printsys();
}
