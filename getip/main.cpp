#include <iostream>
#include <iomanip>
#include <regex>
#include "pcmd.h"
#include <codecvt>

using namespace std;
using namespace pcmd;

void getip(bool);
int main(int argc, char** argv) {
    if (loadPCMD()) {
        bool help = false;
        bool doSimple = false;

        if (argc > 1) {
            for (int i = 1; i < argc; i++) {
                string arg = argv[i];

                if (arg == "-h" || arg == "?") {
                    help = true;
                }
                else if (arg == "-s") {
                    doSimple = true;
                }
            }
        }

        if (help) {
            cout << "Option:" << endl;
            cout << "  -s\tShow simply" << endl;
        }
        else {
            getip(doSimple);
        }

        unloadPCMD();
    }
    else {
        cout << "pcmd.dll load failed" << endl;
    }
}

void getip(bool doSimple) {
    regex regexName(R"(^(?! )(.+):)");
    regex regexIP(R"(.*IPv4.+(\.| )+: *(\d+\.\d+\.\d+\.\d+).*)");
    smatch match;

    string ipName = "";
    string ipAddr = "";

    runAndIter("ipconfig", [&](string str) {
        if (regex_match(str, match, regexName)) {
            ipName = match[1].str();
        }
        else if (!ipName.empty() && regex_match(str, match, regexIP)) {
            ipAddr = match[2].str();
            if (doSimple) {
                cout << ipAddr << endl;
            }
            else {
                cout << left << setw(16) << ipAddr << ipName << endl;
            }
        }
        return 0;
    });
}