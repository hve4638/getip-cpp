#include "pch.h"
#include "pcmd.h"
#include "ProxyCMD.h"

using namespace std;

void run(string cmd) {
    ProxyCMD Cmd = cmd;
}

void runAndGet(string cmd, string& result) {
    ProxyCMD Cmd = cmd;
    result = Cmd.getlines();
}

void runAndIter(string cmd, CMDCallback callback) {
    ProxyCMD Cmd = cmd;
    Cmd.iter(callback);
}