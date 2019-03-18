/* ----------------------------------------------- */
/* Chap. 8.7 - A Storage Allocator   --- kr185-189 */
/* ----------------------------------------------- */

/* --- 
 Compiled by Kathrin Meyer, University of Fribourg, July 2006 
 Main program developed by Beat Hirsbrunner and Fulvio Frapolli, January 2008
 --- */

#include<stdio.h>  // NULL
#define TRUE 1
#define FALSE 0
#define DIM 10
#define MAX 10000

/* ------------------------ */
/* Declarations  ---  kr187 */
/* ------------------------ */
typedef long Align; /* for alignment to long boundary */

union header { /* block header */
	struct {
		union header *ptr; /* next block if on free list */
		unsigned size; /* size of this block */
	} s;
	Align x; /* force alignment of blocks */
};

typedef union header Header;

/* ---------------------------------------------------- */
/* malloc:  general-purpose storage allocator --- kr187 */
/* ---------------------------------------------------- */
static Header base; /* empty list to get started */
static Header *freep= NULL; /* start of free list */

void *malloc(unsigned nbytes) {
	Header *p, *prevp;
	Header *morecore(unsigned);
	unsigned nunits;

	nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
	if ((prevp = freep) == NULL) { /* no free list yet */
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}
	for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr) {
		if (p->s.size >= nunits) { /* big enough */
			if (p->s.size == nunits) /* exactly */
				prevp->s.ptr = p->s.ptr;
			else { /* allocate tail end */
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *)(p+1);
		}
		if (p == freep) /* wrapped around free list */
			if ((p = morecore(nunits)) == NULL)
				return NULL; /* none left */
	}
}

/* ---------------------------------------------- */
/* morecore: ask system for more memory --- kr188 */
/* ---------------------------------------------- */
#define NALLOC  1024   /* minimum #units to request */
void free(void *ap);

Header *morecore(unsigned nu) {
	char *cp, *sbrk(int);
	Header *up;

	if (nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(Header));
	if (cp == (char *) -1) /* no space at all */
		return NULL;
	up = (Header *) cp;
	up->s.size = nu;
	free((void *)(up+1));
	return freep;
}

/* ----------------------------------------- */
/* free: put block ap in free list --- kr188 */
/* ----------------------------------------- */
void free(void *ap) {
	Header *bp, *p;

	bp = (Header *)ap - 1; /* point to  block header */
	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break; /* freed block at start or end of arena */

	if (bp + bp->s.size == p->s.ptr) { /* join to upper nbr */
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	} else
		bp->s.ptr = p->s.ptr;
	if (p + p->s.size == bp) { /* join to lower nbr */
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	} else
		p->s.ptr = bp;
	freep = p;
}

void print_usage()
//----------------
{
	printf("\n--- The following commands should be used with a performance tool like 'vmstat' ot 'top'.\n"
		"Under Mac OS X 10.3 or later, one can also use the graphical tool 'Activity Monitor'.---\n"
		"Use CTRL-C to stop the program before crashing you machine!!!\n");
	printf("malloc/free usage:  M)Fill Memory with malloc F)Verify memory deallocation (malloc/free) \n ");
	printf("Test program usage: H)Help  Q)Quit\n");
}

main() /* Test program for the alloc/afree functions */
{

	long li, grain = 1048576; // 2 ** 20
	char c;
	int k;
	char *prompt = ">";
	int *i, *j[MAX];
	print_usage();
	printf("%s", prompt);

	/*---------------------------
	 Main loop of the test program
	 ---------------------------*/
	while (c = getchar()) {
		switch (c) {

		case 'M': // Fill the memory with malloc
			li=0;
			while (TRUE) {
				if ((i = (int *) malloc(sizeof(int)))==NULL)
					goto error1;
				else {
					if ( !(++li % grain))
						printf("%d\n", li/grain);
				}
			}
			break;

		case 'F': //Verify memory deallocation  malloc/free
			li=0;
			for (k=0; k<MAX; k++) {
				if ((j[k]= (int *) malloc(MAX * sizeof(int)))==NULL)
					goto error1;
			}

			for (k=0; k<MAX; k++) {
				if (j[k]==NULL)
					break;
				printf("free %d",k);
				free(j[k]);
			}
			break;

		case 'H': // Help
			print_usage();
			break;

		case 'Q': // Quit
			return 0;

		default:
			print_usage();
			break;
		}
		while (getchar() != '\n') {
		} /* skip end of line */
		printf("%s", prompt);
		continue; // all is ok, go to the beginning of the main loop

		/*----- ERROR TREATMENT -----*/

		error1: while (getchar() != '\n') {
		} /* skip end of line */
		printf("test program> ERROR: Memory is full and has not been allocated\n");
		printf("%s", prompt);
		continue; // retry, go to the beginning of the main loop


		/*----- END ERROR TREATMENT -----*/
	}
	/*--------------------------------------
	 End of the main loop of the test program
	 --------------------------------------*/
}
