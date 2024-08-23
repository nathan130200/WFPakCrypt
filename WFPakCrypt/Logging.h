#ifndef _HAS_LOGGING_H_
#define _HAS_LOGGING_H_

typedef void (*LogCallback)(const char* msg);

static LogCallback g_LogCallback = nullptr;

void _LOGMSG(const char* format, ...);

#ifndef LOGMSG
#define LOGMSG(Format, ...) _LOGMSG(__FUNCTION__ "(): " Format, __VA_ARGS__)
#endif

#endif