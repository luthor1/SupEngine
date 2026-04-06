#include "Core/Application.hpp"
#include <spdlog/spdlog.h>

namespace Sup {

    Application::Application() {
        m_Window = std::make_unique<Window>(WindowProps("SupEngine (Vulkan)", 1280, 720));
    }

    Application::~Application() {
    }

    void Application::Run() {
        spdlog::info("Application is starting...");

        while (m_Running) {
            m_Window->OnUpdate();

            if (m_Window->ShouldClose()) {
                m_Running = false;
            }
        }
        
        spdlog::info("Application is closing...");
    }

} // namespace Sup
