#pragma once
#ifndef DELIM_TEXT_BUFFER_H
#define DELIM_TEXT_BUFFER_H
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

class DelimTextBuffer {
public:
	DelimTextBuffer(char Delim = '^', int maxBytes = 1000);
	int Read(istream& file);
	int Write(ostream& file) const;
	int Pack(const char* cadena, int size = -1);
	char* Unpack();
	void Clear();

	void setNextByte(int);

	int BufferSize;
private:
	char Delim;
	char* Buffer;
	int MaxBytes;
	int NextByte;
};

#endif // !DELIM_TEXT_BUFFER_H