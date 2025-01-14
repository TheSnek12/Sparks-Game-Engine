#include <stdint.h>
#include <Logger/Logger.h>
#include <glad/glad.h>
#include "IRenderEngine.h"

namespace s_Renderer
{
    enum Platform{
        LINUX,
        WINDOWS,
        MACOS,
//      MOBILE

    };

    class OpenGLRenderEngine : public IRenderEngine
    {
    private:
        Platform _platform;
        uint16_t _width;
        uint16_t _height;

        GLADloadproc _procAddr;
        
    public:
        bool initRenderer() override;
        bool destroyRenderer() override;
        void addObjectToQueue() override;
        void drawFrame() override;



        OpenGLRenderEngine(Platform platform, uint16_t width, uint16_t height, GLADloadproc procAddr);
        OpenGLRenderEngine(Platform platform, uint16_t width, uint16_t height);


    };

} // namespace s_Render
