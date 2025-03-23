#pragma once
#include "src/Renderer/RenderObject.h"
#include "Renderer/IRenderEngine.h"
namespace sparks

{
    enum Renderer
    {
        OpenGL
    };
    class IContext
    {
    public:
        virtual bool init() = 0;
        virtual void setActiveCamera(s_Renderer::Cam cam) = 0;
        virtual void addDirLight(s_Renderer::DirLight dirLight) = 0;
        virtual void addPointLight(s_Renderer::PointLight pointLight) = 0;
        virtual void addSpotLight(s_Renderer::SpotLight spotLight) = 0;
        virtual bool cleanup() = 0;
        virtual s_Renderer::Renderer engineType() = 0;
        virtual void selectEngine(Renderer renderer) = 0;
        virtual void sendToRenderPool(s_Renderer::RenderObject* renderObj) = 0;
        virtual void close() = 0;
        virtual void abort() = 0;
        virtual void resize(uint16_t width, uint16_t height) = 0;
    };
} // namespace sparks