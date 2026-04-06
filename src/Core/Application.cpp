#include "Core/Application.hpp"
#include <spdlog/spdlog.h>

namespace Sup {

    Application::Application() {
        m_Window = std::make_unique<Window>(WindowProps("SupEngine (Vulkan)", 1280, 720));
        m_VulkanContext = std::make_unique<VulkanContext>(m_Window.get());
    }

    Application::~Application() {
    }

    void Application::Run() {
        spdlog::info("Application is starting...");

        while (m_Running) {
            m_Window->OnUpdate();
            m_VulkanContext->DrawFrame();

            if (m_Window->ShouldClose()) {
                m_Running = false;
            }
        }
        
        spdlog::info("Application is closing...");
    }

} // namespace Sup
