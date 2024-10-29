#pragma once

#include <iostream>
#include <string>
#include <cstdarg>
#include <memory>

/**
 * Logs a message to the console. The message is formatted
 * according to the given format string, and the additional
 * arguments are used to fill in the format specifiers. The
 * message is followed by a newline character.
 *
 * The format string is a C-style format string, and the
 * arguments should be of the same types as required by the
 * format specifiers in the format string.
 *
 * @param format The format string
 * @param ... The arguments to fill in the format string
 */
void Log(const std::string& format, ...)
{
    va_list args;
    va_start(args, format);

    size_t size = std::vsnprintf(nullptr, 0, format.c_str(), args) + 1;// Extra space for '\0'
    std::unique_ptr<char[]> buf(new char[size]);
    std::vsnprintf(buf.get(), size, format.c_str(), args);
    va_end(args);

    std::cout << buf.get() << std::endl;
}
