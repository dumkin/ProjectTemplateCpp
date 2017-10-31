#pragma once

#include "style.hpp"
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#define OUT_TYPE_CONSOLE 0
#define OUT_TYPE_FILE 1

#define FILE_TYPE_UNIQUE 0
#define FILE_TYPE_APPEND 1
#define FILE_TYPE_REWRITE 2

class dLog {
	public:
	dLog();
	dLog(int outType);
	dLog(int outType, int fileType);
	dLog(int outType, int fileType, std::string newFilename);
	~dLog();

	bool setOutType(int outType);
	bool setFileType(int fileType);
	bool setFileName(std::string fileName);
	bool setConsoleTheme(theme consoleTheme);

	int getOutType();
	int getFileType();
	std::string getFileName();
	theme getConsoleTheme();

	std::string getDate();

	bool write(std::string text, bool newLine = true);

	private:
	bool start();
	bool stop();

	style _css;
	theme _consoleTheme;
	std::fstream _fileStream;

	int _outType          = OUT_TYPE_FILE;
	int _fileType         = FILE_TYPE_UNIQUE;
	bool _started         = false;
	std::string _fileName = u8"App.log";
};