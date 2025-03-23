#include <Scriptables/PointLight.h>
namespace sparks
{
    PointLight::PointLight(){

    }
    void PointLight::onStart(){
        light = s_Renderer::PointLight();
        light.pos = &object->getScriptable<Transform>()->position;
        light.luminance = &luminance;
        light.color = &color;
        Context::getContext()->addPointLight(light);
    }
    PointLight::~PointLight(){
        Context::getContext()->removePointLight(light);
    }
} // namespace sparks
