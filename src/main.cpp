#include "Core/Application.hpp"
#include <spdlog/spdlog.h>
#include <exception>

int main() {
    try {
        Sup::Application app;
        app.Run();
    } catch (const std::exception& e) {
        spdlog::critical("Fatal Error: {}", e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
