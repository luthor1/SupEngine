#pragma once

#include <vulkan/vulkan.h>
#include <vector>

namespace Sup {

    class Window;

    class VulkanContext {
    public:
        VulkanContext(Window* window);
        ~VulkanContext();

        VulkanContext(const VulkanContext&) = delete;
        VulkanContext& operator=(const VulkanContext&) = delete;

        void Init();

    private:
        void CreateInstance();
        void SetupDebugMessenger();
        
        // Validation layers and extensions
        bool CheckValidationLayerSupport();
        std::vector<const char*> GetRequiredExtensions();

    private:
        Window* m_Window;

        VkInstance m_Instance;
        VkDebugUtilsMessengerEXT m_DebugMessenger;

        const std::vector<const char*> m_ValidationLayers = {
            "VK_LAYER_KHRONOS_validation"
        };

#ifdef NDEBUG
        const bool m_EnableValidationLayers = false;
#else
        const bool m_EnableValidationLayers = true;
#endif
    };

} // namespace Sup
