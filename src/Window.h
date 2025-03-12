#pragma once
#include "IContext.h"
#include "Base.h"
#include "Renderer/Renderer.h"

namespace sparks
{

    class Window
    {
    public:
        virtual bool initWindow() = 0;
        virtual bool prepareForRenderer(s_Renderer::Renderer renderEngine) = 0;
        virtual bool destroyWindow() = 0;
        virtual void pollWindowEvents() = 0;
        virtual void resize(uint16_t width, uint16_t height) = 0;

        uint16_t width;
        uint16_t height;
        const char * title;
        
        typedef void* (* procAddr)(const char *name);
        virtual procAddr getGLProcAddr() = 0;
        virtual procAddr getVKProcAddr() = 0;
        Window(IContext *context, uint16_t width, uint16_t height, const char* title);
        ~Window() = default;

    protected:
        IContext *_context;
    };
} // namespace sparks