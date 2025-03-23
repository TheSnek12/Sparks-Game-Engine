#pragma once
#include <stdint.h>
#include <Logger/Logger.h>
#include <glad/glad.h>
#include "OpenGLSSBO.h"
#include "../IRenderEngine.h"


namespace s_Renderer
{

    

    class OpenGLRenderEngine : public IRenderEngine
    {
    private:
        Platform _platform;
        uint16_t _width;
        uint16_t _height;
        Cam camera;
        std::vector<SpotLight> spotLights;
        std::vector<PointLight> pointLights;
        std::vector<DirLight> dirLights;

        OpenGLSSBO<DirLightData>* dirSSBO;
        OpenGLSSBO<PointLightData>* pointSSBO;
        OpenGLSSBO<SpotLightData>* spotSSBO;

        std::vector<RenderObject*> _objectQueue;

        GLADloadproc _procAddr;
        
    public:
        bool initRenderer() override;
        bool destroyRenderer() override;
        void addObjectToQueue(RenderObject* renderObject) override;
        void drawFrame() override;
        Renderer rendererType() override;
        void setCamera(Cam cam) override;
        void addPointLight(PointLight light) override;
        void removePointLight(PointLight light) override;
        void addDirLight(DirLight light) override;
        void removeDirLight(DirLight light) override;
        void addSpotLight(SpotLight light) override;
        void removeSpotLight(SpotLight light) override;
        OpenGLRenderEngine(Platform platform, uint16_t width, uint16_t height, GLADloadproc procAddr);
        OpenGLRenderEngine(Platform platform, uint16_t width, uint16_t height);


    };

} // namespace s_Render