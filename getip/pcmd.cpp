#include "pcmd.h"
#include <tchar.h>

namespace pcmd {
    static HMODULE hModule;
    RunFunc run = NULL;
    RunAndGetFunc runAndGet = NULL;
    RunAndIterFunc runAndIter = NULL;

    bool loadPCMD() {
        if ((hModule = LoadLibrary(_T("./pcmd.dll"))) == NULL) {
            unloadPCMD();
            return false;
        }
        else if ((run = (RunFunc)GetProcAddress(hModule, "run")) == NULL) {
            unloadPCMD();
            return false;
        }
        else if ((runAndGet = (RunAndGetFunc)GetProcAddress(hModule, "runAndGet")) == NULL) {
            unloadPCMD();
            return false;
        }
        else if ((runAndIter = (RunAndIterFunc)GetProcAddress(hModule, "runAndIter")) == NULL) {
            unloadPCMD();
            return false;
        }
        else {
            return true;
        }
    }

    void unloadPCMD() {
        if (hModule != NULL) {
            FreeLibrary(hModule);
            hModule = NULL;
        }

        run = NULL;
        runAndGet = NULL;
        runAndIter = NULL;
    }
}