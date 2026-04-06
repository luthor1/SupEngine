#pragma once

#include "Core/Window.hpp"
#include "Renderer/VulkanContext.hpp"
#include <memory>

namespace Sup {

    class Application {
    public:
        Application();
        virtual ~Application();

        // Start the game engine loop
        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        std::unique_ptr<VulkanContext> m_VulkanContext;
        bool m_Running = true;
    };

} // namespace Sup
