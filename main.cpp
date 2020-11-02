#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"

#include <iostream>
#include <memory>

int main(int, char**) {

    spdlog::set_error_handler([](const std::string &msg) { std::cerr << "error handler: " << msg.c_str() << "\n"; });

    auto stdout_logger =
        std::make_shared<spdlog::logger>("stdout_logger", std::make_shared<spdlog::sinks::stdout_sink_mt>());
    spdlog::initialize_logger(stdout_logger);

    const char *terminated_chars = "Hello, World!";
    stdout_logger->info("terminated: {0}", terminated_chars);

    // Hello, World!
    const char non_terminated_chars[] =
        {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'};

    stdout_logger->info("no terminated: {0}", non_terminated_chars);

    return 0;
}
