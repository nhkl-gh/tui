#pragma once

#include <iomanip>
#include <iostream>

#define ANSI_COL_YELLOW "\x1b[33m"
#define ANSI_COL_RESET "\x1b[0m"
#define ANSI_COL_RED "\x1b[31m"

void warn(std::string msg) {
  std::cout << ANSI_COL_YELLOW << "[WARN]" << std::get_time(&msg, "%H:%M:%S") << " " << msg << ANSI_COL_RESET << std::endl;
}
