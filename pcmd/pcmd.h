#pragma once
#include "pch.h"

extern "C" void PCMD_API run(std::string);
extern "C" void PCMD_API runAndGet(std::string, std::string&);
extern "C" void PCMD_API runAndIter(std::string, CMDCallback);