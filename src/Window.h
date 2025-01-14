#ifndef HWINDOW
#define HWINDOW

#include <Game.h>
#include "IContext.h"
#include "Base.h"

namespace sparks
{
    class IContext;

    class Window
    {
    public:
        virtual bool initWindow() = 0;
        virtual bool destroyWindow() = 0;
        virtual void pollWindowEvents() = 0;
        
        typedef void* (* procAddr)(const char *name);
        virtual procAddr getGLProcAddr() = 0;
        virtual procAddr getVKProcAddr() = 0;
        Window(IContext *context) : _context(context) {};
        ~Window() = default;

    protected:
        IContext *_context;
    };
} // namespace sparks
#endif