#include <Scriptables/DirectionalLight.h>
namespace sparks
{
    DirectionalLight::DirectionalLight(){

    }
    void DirectionalLight::onStart(){
        light = s_Renderer::DirLight();
        light.rot = &object->getScriptable<Transform>()->rotation;
        light.luminance = &luminance;
        light.color = &color;
        Context::getContext()->addDirLight(light);
    }
    DirectionalLight::~DirectionalLight(){
        Context::getContext()->removeDirLight(light);
    }
} // namespace sparks
