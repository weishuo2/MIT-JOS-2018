// Simple implementation of cprintf console output for the kernel,
// based on printfmt() and the kernel console's cputchar().

#include <inc/types.h>
#include <inc/stdio.h>
#include <inc/stdarg.h>


static void
putch(int ch, int *cnt)//调用了console中的cputchar
{
	cputchar(ch);
	*cnt++;
}

int
vcprintf(const char *fmt, va_list ap)// 调用了\lib\printfmt.c 中的vprintfmt
{
	int cnt = 0;

	vprintfmt((void*)putch, &cnt, fmt, ap);
	return cnt;
}

int
cprintf(const char *fmt, ...)// 调用了\lib\printfmt.c 中的vprintfmt
{
	va_list ap;
	int cnt;

	va_start(ap, fmt);
	cnt = vcprintf(fmt, ap);
	va_end(ap);

	return cnt;
}

