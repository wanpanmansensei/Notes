#pragma once
#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <sstream>	//for istringstream
#include <ctime>
using namespace std;

using col = const std::string;
col grey = "\033[1;30m";
col red = "\033[1;31m";
col green = "\033[1;32m";
col yel = "\033[1;33m";
col blue = "\033[1;34m";
col mag = "\033[1;35m";
col cyan = "\033[1;36m";
col white = "\033[1;37m";

col lgrey = "\033[0;30m";
col lred = "\033[0;31m";
col lgreen = "\033[0;32m";
col lyel = "\033[0;33m";
col lblue = "\033[0;34m";
col lmag = "\033[0;35m";
col lcyan = "\033[0;36m";
col lwhite = "\033[0;37m";

col ugrey = "\033[4;30m";
col ured = "\033[4;31m";
col ugreen = "\033[4;32m";
col uyel = "\033[4;33m";
col ublue = "\033[4;34m";
col umag = "\033[4;35m";
col ucyan = "\033[4;36m";
col uwhite = "\033[4;37m";

col bgrey = "\033[1;40m";
col bred = "\033[1;41m";
col bgreen = "\033[1;42m";
col byel = "\033[1;43m";
col bblue = "\033[1;44m";
col bmag = "\033[1;45m";
col bcyan = "\033[1;46m";
col bwhite = "\033[1;47m";

col res = "\033[0m";

col Coff = "\e[?25l";
col Con = "\e[?25h";
