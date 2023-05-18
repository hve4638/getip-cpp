#include "pch.h"
#include "ProxyCMD.h"
#include <string>
#include <vector>

vector<string> splitString(const std::string& input, char delimiter) {
	std::vector<std::string> result;
	std::size_t start = 0;
	std::size_t end = input.find(delimiter);

	while (end != std::string::npos) {
		result.push_back(input.substr(start, end - start));
		start = end + 1;
		end = input.find(delimiter, start);
	}

	result.push_back(input.substr(start, end));
	return result;
}

using namespace std;

ProxyCMD::ProxyCMD(string cmd) {
	m_pipe = _popen(cmd.c_str(), "r");
}
ProxyCMD::~ProxyCMD() {
	_pclose(m_pipe);
}

void ProxyCMD::iter(CMDCallback callback) {
	string result = getlines();
	vector<string> lines = splitString(result, '\n');
	for (string line : lines) {
		callback(line);
	}
}

bool ProxyCMD::tryGetline(string& line) {
	if (fgets(m_buffer, sizeof(m_buffer), m_pipe) != nullptr) {
		line = m_buffer;
		return true;
	}
	else {
		line.clear();
		return false;
	}
}
string ProxyCMD::getlines() {
	string lines;
	string line;
	while (this->tryGetline(line)) {
		lines += line;
	}
	return lines;
}




