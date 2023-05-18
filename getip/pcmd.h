#pragma once
#include <Windows.h>
#include <functional>
#include <string>

namespace pcmd {
	typedef std::function<int(std::string)> IterCallback;

	typedef bool(*RunFunc)(std::string);
	typedef void(*RunAndGetFunc)(std::string, std::string&);
	typedef void(*RunAndIterFunc)(std::string, IterCallback);

	extern RunFunc run;
	extern RunAndGetFunc runAndGet;
	extern RunAndIterFunc runAndIter;

	extern bool loadPCMD();
	extern void unloadPCMD();
}