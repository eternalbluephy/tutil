#include "TUtil/terminsz.h"

#if defined(linux) || defined(unix)
#include <sys/ioctl.h>
void getTermSize(int *w, int *h)
{
	struct winsize size;
	ioctl(0, TIOCGWINSZ, &size);
	*w = size.ws_col;
	*h = size.ws_row;
}
#endif

#ifdef _WIN32

#endif
