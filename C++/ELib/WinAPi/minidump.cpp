include <Windows.h>
#include <DbgHelp.h>
#include <cstdio>
#include <string>
 
using namespace std;
 
#pragma comment(lib, "dbghelp.lib")
 
LONG __stdcall TopLvFilter(PEXCEPTION_POINTERS pExceptionPointer)
{
    MINIDUMP_EXCEPTION_INFORMATION MinidumpExceptionInformation;
    std::wstring DumpFileName = L"dmpfile.dmp";
 
    MinidumpExceptionInformation.ThreadId = ::GetCurrentThreadId();
    MinidumpExceptionInformation.ExceptionPointers = pExceptionPointer;
    MinidumpExceptionInformation.ClientPointers = FALSE;
 
    if (DumpFileName.empty() == true)
    {
        ::TerminateProcess(::GetCurrentProcess(), 0);
    }
 
    HANDLE hDumpFile = ::CreateFile(DumpFileName.c_str(),
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        nullptr,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL, nullptr);
 
    MiniDumpWriteDump(GetCurrentProcess(),
        GetCurrentProcessId(),
        hDumpFile,
        MiniDumpNormal,
        &MinidumpExceptionInformation,
        nullptr,
        nullptr);
 
    ::TerminateProcess(::GetCurrentProcess(), 0);
 
    return 0;
}
void InvalidParameterHandler(const wchar_t* expression, const wchar_t* function, const wchar_t* file, unsigned int line, uintptr_t pReserved)
{
    EXCEPTION_POINTERS ExceptionPointer;
    EXCEPTION_RECORD ExceptionRecord;
    _CONTEXT ContextRecord;
 
    ZeroMemory(&ContextRecord, sizeof(ContextRecord));
    RtlCaptureContext(&ContextRecord);
 
    ZeroMemory(&ExceptionRecord, sizeof(EXCEPTION_RECORD));
    ExceptionRecord.ExceptionCode = STATUS_INVALID_CRUNTIME_PARAMETER;  
    ExceptionRecord.ExceptionAddress = (PVOID)ContextRecord.Eip;
         
    ExceptionPointer.ExceptionRecord = &ExceptionRecord;
    ExceptionPointer.ContextRecord = &ContextRecord;
 
    TopLvFilter(&ExceptionPointer);
}
void main()
{
    SetUnhandledExceptionFilter(TopLvFilter);
    _set_invalid_parameter_handler(InvalidParameterHandler);
    atoi(nullptr);   
