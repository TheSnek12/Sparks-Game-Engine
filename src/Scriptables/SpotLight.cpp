#include <Scriptables/SpotLight.h>
namespace sparks
{
    SpotLight::SpotLight(){

    }
    void SpotLight::onStart(){
        light = s_Renderer::SpotLight();
        light.radius = &radius;
        light.innerRadius = &innerRadius;
        light.dir = &object->getScriptable<Transform>()->rotation;
        light.pos = &object->getScriptable<Transform>()->position;
        light.luminance = &luminance;
        light.color = &color;
        Context::getContext()->addSpotLight(light);
    }
    SpotLight::~SpotLight(){
        Context::getContext()->removeSpotLight(light);
    }
} // namespace sparks
