#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "Client.h"
#include "Admin.h"
#include "Employee.h"

using namespace std;

class Parser {

	public:
	static vector<string> split(string line) {
		// ahmed&ahmed123&2000
		stringstream s(line);
		vector<string> info;
		string data;
		while (getline(s, data, '&')) {
			info.push_back(data);
		}
		return info;
	}

	static Client parseToClient(string line) {
		vector<string> info = split(line);
		Client c(info[0], info[1], stod(info[2]));
		return c;
	}

	static Admin parseToAdmin(string line) {
		vector<string> info = split(line);
		Admin a(info[0], info[1], stod(info[2]));
		return a;
	}

	static Employee parseToEmployee(string line) {
		vector<string> info = split(line);
		Employee e(info[0], info[1], stod(info[2]));
		return e;
	}

};
