#include "Core/Window.hpp"
#include <spdlog/spdlog.h>

namespace Sup {

    static bool s_GLFWInitialized = false;

    Window::Window(const WindowProps& props) {
        Init(props);
    }

    Window::~Window() {
        Shutdown();
    }

    void Window::Init(const WindowProps& props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        spdlog::info("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized) {
            int success = glfwInit();
            if (!success) {
                spdlog::critical("Could not initialize GLFW!");
                return;
            }
            s_GLFWInitialized = true;
        }

        // We are using Vulkan, so we don't want an OpenGL context
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        // Disable window resizing for now, as Vulkan swapchain recreation is complex
        // We'll handle it later
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        
        // Setup user pointer so we can pass our own data to callbacks later
        glfwSetWindowUserPointer(m_Window, &m_Data);
    }

    void Window::Shutdown() {
        glfwDestroyWindow(m_Window);
        if (s_GLFWInitialized) {
            glfwTerminate();
            s_GLFWInitialized = false;
        }
    }

    void Window::OnUpdate() {
        glfwPollEvents();
    }

    bool Window::ShouldClose() const {
        return glfwWindowShouldClose(m_Window);
    }

} // namespace Sup
