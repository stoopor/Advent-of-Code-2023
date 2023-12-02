#pragma once
#include "helper.h"
bool loadInput(ifstream* stream, string filename) {
	stream->open(filename);
	stream->seekg(0, ios::beg);
	if (stream == NULL) return false;
	return true;
}