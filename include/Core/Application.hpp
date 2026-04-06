#pragma once

#include "Core/Window.hpp"
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
        bool m_Running = true;
    };

} // namespace Sup
