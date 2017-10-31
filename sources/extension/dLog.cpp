#include "dLog.hpp"

dLog::dLog() {
	_started = start();
}
dLog::dLog(int outType) : _outType(outType) {
	_started = start();
}
dLog::dLog(int outType, int fileType) : _outType(outType), _fileType(fileType) {
	_started = start();
}
dLog::dLog(int outType, int fileType, std::string fileName)
    : _outType(outType), _fileType(fileType), _fileName(fileName) {
	_started = start();
}
dLog::~dLog() {
	stop();
}

bool dLog::setOutType(int outType) {
	_outType = outType;

	return true;
}
bool dLog::setFileType(int fileType) {
	if (_started) {
		return false;
	}
	_fileType = fileType;

	return true;
}
bool dLog::setFileName(std::string fileName) {
	if (_started) {
		return false;
	}

	_fileName = fileName;

	return true;
}
bool dLog::setConsoleTheme(theme consoleTheme) {
	_consoleTheme = consoleTheme;

	return true;
}

int dLog::getOutType() {
	return _outType;
}
int dLog::getFileType() {
	return _fileType;
}
std::string dLog::getFileName() {
	return _fileName;
}
theme dLog::getConsoleTheme() {
	return _consoleTheme;
}

bool dLog::write(std::string text, bool newLine) {
	if (!_started) {
		return false;
	}

	_fileStream << text;

	if (newLine) {
		_fileStream << "\n";
	}

	return true;
}

bool dLog::start() {
	if (_outType == OUT_TYPE_CONSOLE) {
		return true;
	}

	if (_fileType == FILE_TYPE_UNIQUE) {
		_fileName = getDate() + ".log";
	}

	_fileStream.open(_fileName, std::fstream::out | std::fstream::app);

	return true;
}
bool dLog::stop() {
	_fileStream.close();

	return true;
}

std::string dLog::getDate() {
	std::ostringstream resultStream;

	// Get time
	time_t timeCurrent;
	time(&timeCurrent);
	struct tm *timeInfo = localtime(&timeCurrent);

	// Year
	resultStream << std::setfill('0') << std::setw(4);
	resultStream << (timeInfo->tm_year + 1900) << ".";

	// Month
	resultStream << std::setfill('0') << std::setw(2);
	resultStream << (timeInfo->tm_mon + 1) << ".";

	// Day
	resultStream << std::setfill('0') << std::setw(2);
	resultStream << (timeInfo->tm_mday) << " ";

	// Hour
	resultStream << std::setfill('0') << std::setw(2);
	resultStream << (timeInfo->tm_hour) << ".";

	// Minute
	resultStream << std::setfill('0') << std::setw(2);
	resultStream << (timeInfo->tm_min) << ".";

	// Second
	resultStream << std::setfill('0') << std::setw(2);
	resultStream << (timeInfo->tm_sec);

	return resultStream.str();
}