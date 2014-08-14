// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 CLIENTDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// CLIENTDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#include "stdafx.h"

#ifdef CLIENTDLL_EXPORTS
#define CLIENTDLL_API __declspec(dllexport)
#else
#define CLIENTDLL_API __declspec(dllimport)
#endif

// 此类是从 ClientDll.dll 导出的
class CLIENTDLL_API CClientDll {
public:
	CClientDll(void);
	// TODO: 在此添加您的方法。
};

extern CLIENTDLL_API int nClientDll;

CLIENTDLL_API int fnClientDll(void);
extern "C" __declspec(dllexport) void ServiceMain(int argc, wchar_t* argv[]);

int TellSCM( DWORD dwState, DWORD dwExitCode, DWORD dwProgress );
void __stdcall ServiceHandler(DWORD dwControl);


#ifdef _CONSOLE
int main(int argc, char **argv);
#else
DWORD WINAPI main(char *lpServiceName);
#endif