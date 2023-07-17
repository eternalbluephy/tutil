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
#include <Windows.h>
void getTermSize(int *w, int *h)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	w = (int)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
	h = (int)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
}
#ifdef _WIN32

#endif
