#pragma once
#include "pch.h"
#include <string>

using namespace std;

class PCMD_API ProxyCMD {
	char m_buffer[256] = { 0, };
	FILE* m_pipe;

public:
	ProxyCMD(string cmd);
	~ProxyCMD();

	void iter(CMDCallback);
	bool tryGetline(string& line);
	string getlines();
};