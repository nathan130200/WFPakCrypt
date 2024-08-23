#include "WFPakCrypt.h"
#include <iostream>
#include <vector>
//#include <stdarg.h>

void SetLogCallback(LogCallback callback)
{
	g_LogCallback = callback;
}

void _LOGMSG(const char* format, ...)
{
	if (!g_LogCallback)
		return;

	va_list ap;
	va_start(ap, format);

	std::vector<char> buf;
	int count = vsnprintf(nullptr, 0, format, ap);
	buf.resize(count + 1);
	vsnprintf(buf.data(), count, format, ap);
	g_LogCallback(buf.data());
}