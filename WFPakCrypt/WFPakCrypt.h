#pragma once

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#define LTC_SOURCE
#define LTC_NO_PROTOTYPES
#include <tomcrypt.h>
#undef LTC_SOURCE
#undef LTC_NO_PROTOTYPES

#define WFPAKCRYPT_API_NO_PARAM(ReturnType, FuncName) __declspec(dllexport) ReturnType FuncName()
#define WFPAKCRYPT_API(ReturnType, FuncName, ...) __declspec(dllexport) ReturnType FuncName(__VA_ARGS__)

#include "StdLib.h"
#include "Classes.h"
#include "ZipEncrypt.h"
#include "ZipDir.h"
#include "Logging.h"

#ifdef __cplusplus
extern "C"
{
#endif

	WFPAKCRYPT_API(bool, InitRSA, unsigned char* key, int keySize);
	WFPAKCRYPT_API(bool, DecryptPak, const char* fin, const char* fout, bool older_support);
	WFPAKCRYPT_API_NO_PARAM(bool, CleanupRSA);
	WFPAKCRYPT_API(void, SetLogCallback, LogCallback callback);

#ifdef __cplusplus
}
#endif