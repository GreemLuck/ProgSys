/* ----------------------------------------------------------------------------
fopen, fclose and getc Illustration: Copy input file to outpuf file

Fulvio Frapolli and Amos Brocco, University of Fribourg, January 2008
---------------------------------------------------------------------------- */

#include <fcntl.h>
#include "my_stdio.h" /* --- kr176 */ // getc
#include <stdlib.h>
#include <stdarg.h>

#define PERMS 0666    /* RW for owner, group, others */

extern int printf(__const char *__restrict __format, ...);

/*--- kr177 */
FILE *fopen(char *name, char *mode) {
	int fd;
	FILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if ((fp->flag & (_READ | _WRITE)) == 0)
			break; /* found free slot */
	if (fp >= _iob + OPEN_MAX) /* no free slots */
		return NULL;

	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);
	if (fd == -1) /* couldn't access name */
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ? _READ : _WRITE;
	return fp;
}

/* ---  kr178 */
/* _fillbuf:  allocate and fill input buffer */
int _fillbuf(FILE *fp) {
	int bufsize;

	if ((fp->flag&(_READ| _EOF| _ERR)) != _READ)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL) /* no buffer yet */
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF; /* can't get buffer */
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flag |= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}

/* --- kr178 */
FILE _iob[OPEN_MAX] = { /* stdin, stdout, stderr */
{ 0, (char *) 0, (char *) 0, _READ, 0 },
		{ 0, (char *) 0, (char *) 0, _WRITE, 1 }, { 0, (char *) 0, (char *) 0,
				_WRITE | _UNBUF, 2 } };



/* Fulvio Frapolli & Amos Brocco, DIUF, January 2008 */
int _flushbuf(int c, FILE *fp) {
	int num_written, bufsize;
	char uc = c;

	if ((fp->flag & (_WRITE|_EOF|_ERR)) != _WRITE)
		return EOF;
	if (fp->base == NULL && ((fp->flag & _UNBUF) == 0)) {
		// no buffer yet 
		if ((fp->base = malloc(BUFSIZ)) == NULL)
			// couldn't allocate a buffer, so try unbuffered 
			fp->flag |= _UNBUF;
		else {
			fp->ptr = fp->base;
			fp->cnt = BUFSIZ - 1;
		}
	}
	if (fp->flag & _UNBUF) {
		// unbuffered write //
		fp->ptr = fp->base = NULL;
		fp->cnt = 0;
		if (c == EOF)
			return EOF;
		num_written = write(fp->fd, &uc, 1);
		bufsize = 1;
	} else {
		// buffered write 
		if (c != EOF)
			*fp->ptr++ = uc;
		bufsize = (int)(fp->ptr - fp->base);
		num_written = write(fp->fd, fp->base, bufsize);
		fp->ptr = fp->base;
		fp->cnt = BUFSIZ - 1;
	}
	if (num_written == bufsize) {

		return c;
	}

	else {
		fp->flag |= _ERR;
		return EOF;
	}
}


/* fflush:  Fulvio Frapolli & Amos Brocco, DIUF, January 2008 */
int fflush(FILE *f) {
	int retval;
	int i;

	retval = 0;
	if ((f->flag & _WRITE) == 0)
		return -1;
	_flushbuf(EOF, f);

	if (f->flag & _ERR)
		retval = -1;

	return retval;
}


/* fclose:  Fulvio Frapolli & Amos Brocco, DIUF, January 2008 */
int fclose(FILE *f) {
	int fd;

	if (f == NULL)
		return -1;
	fd = f->fd;
	fflush(f);
	f->cnt = 0;
	f->ptr = NULL;
	if (f->base != NULL)
		free(f->base);
	f->base = NULL;
	f->flag = 0;
	f->fd = -1;
	return close(fd);
}

/* -------------*/
/* Main Program */
/* -------------*/
main(int argc, char *argv[]) {

	int c, i=0;
	FILE *f1;
	FILE *f2;

	char buf[BUFSIZ];
	
	if (argc != 3){
		printf("Usage: cp from to\n");
		return -1;
		}
	if ((f1 = fopen(argv[1], "r")) == NULL)
		printf("cp: can't open %s\n", argv[1]);
	if ((f2 = fopen(argv[2], "w")) == NULL)
		printf("cp: can't create %s, mode %03o\n", argv[2], PERMS);
	while ((c = getc(f1))!= EOF) {
		putc(c,f2);
		i++;
	}

	fclose(f1);
	fclose(f2);
	return 0;

}
