#include "../Renderer.h"
#include "OpenGLRenderEngine.h"

namespace s_Renderer
{
    OpenGLRenderEngine::OpenGLRenderEngine(Platform platform, uint16_t width, uint16_t height, GLADloadproc procAddr) : _platform(platform), _width(width), _height(height), _procAddr(procAddr)
    {
    }
    OpenGLRenderEngine::OpenGLRenderEngine(Platform platform, uint16_t width, uint16_t height) : _platform(platform), _width(width), _height(height)
    {
    }

    bool OpenGLRenderEngine::initRenderer()
    {

        if (_procAddr)
        {
            if (!gladLoadGLLoader(_procAddr))
            {
                logger::log(logger::Level::LEVEL_ERROR, "Failed to load external OpenGLLoader! Falling back to default..");

                if (!gladLoadGL())
                {
                    logger::log(logger::Level::LEVEL_FATAL, "Also failed to load using default loader, is OpenGL installed correctly?");
                    return false;
                }
            }
        }
        else
        {

            if (!gladLoadGL())
            {
                logger::log(logger::Level::LEVEL_FATAL, "Failure while loading OpenGL, is OpenGL installed correctly?");
                return false;
            }
        }

        logger::log(logger::LEVEL_LOG, "Successfully initalized OpenGL renderer!");

        glViewport(0, 0, _width, _height);

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        DirLight testLight;
        testLight.color = new Vec3(1, 1, 1);
        testLight.rot = new Vec3(Vec3(1, 1, 1).normalize());
        testLight.luminance = new float(0.25f);

        dirSSBO = new OpenGLSSBO<DirLightData>(1);
        pointSSBO = new OpenGLSSBO<PointLightData>(2);
        spotSSBO = new OpenGLSSBO<SpotLightData>(3);

        return true;
    }

    void OpenGLRenderEngine::addObjectToQueue(RenderObject *renderObject)
    {
        _objectQueue.push_back(renderObject);
    }

    void OpenGLRenderEngine::drawFrame()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // uint ID;
        // uint index = 2;
        // size_t size = sizeof(test);
        // std::vector<test> data;
        // test test;
        // test.hi = Vec3(0.25, 0.50, 0.75);
        // test.a = Vec3(0.25, 0.50, 0.75);
        // test.f = 1.0f;
        // data.push_back(test);

        // glGenBuffers(1, &ID);
        // glBindBufferRange(GL_SHADER_STORAGE_BUFFER, index, ID, 0, size*data.size());
        // glBufferData(GL_SHADER_STORAGE_BUFFER, size*data.size(), data.data(), GL_DYNAMIC_COPY);

        // data.push_back(test);

        // glBindBufferRange(GL_SHADER_STORAGE_BUFFER, index, ID, 0, size*data.size());
        // glBufferData(GL_SHADER_STORAGE_BUFFER, size*data.size(), data.data(), GL_DYNAMIC_COPY);

        std::vector<DirLightData> dirLightData;

        for (size_t i = 0; i < dirLights.size(); i++)
        {
            dirSSBO->data[i].rot = *dirLights[i].rot;
            dirSSBO->data[i].color = *dirLights[i].color;
            dirSSBO->data[i].luminance = *dirLights[i].luminance;
        }
        for (size_t i = 0; i < pointLights.size(); i++)
        {
            pointSSBO->data[i].pos = *pointLights[i].pos;
            pointSSBO->data[i].color = *pointLights[i].color;
            pointSSBO->data[i].luminance = *pointLights[i].luminance;
        }
        for (size_t i = 0; i < spotLights.size(); i++)
        {
            spotSSBO->data[i].pos = *spotLights[i].pos;
            spotSSBO->data[i].innerRadius = *spotLights[i].innerRadius;
            spotSSBO->data[i].radius = *spotLights[i].radius;
            spotSSBO->data[i].dir = *spotLights[i].dir;
            spotSSBO->data[i].color = *spotLights[i].color;
            spotSSBO->data[i].luminance = *spotLights[i].luminance;
        }

        dirSSBO->rebuffer();

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)_width / (float)_height, camera.near, camera.far);

        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 lookDir = glm::normalize(glm::vec3(camera.dir->x, camera.dir->y, camera.dir->z));
        glm::vec3 cameraRight = glm::normalize(glm::cross(up, lookDir));
        glm::vec3 cameraUp = glm::cross(lookDir, cameraRight);
        glm::vec3 cameraPos = glm::vec3(camera.pos->x, camera.pos->y, camera.pos->z);

        glm::mat4 view = glm::lookAt(
            cameraPos,
            cameraPos + lookDir,
            cameraUp);

        for (RenderObject *obj : _objectQueue)
        {
            if (obj->shader->isCompiled())
            {
                obj->mesh->bind();
                obj->shader->bind();
                for (int i = 0; i < obj->textures.size(); i++)
                {
                    obj->textures[i]->bind(i);
                }

                glm::vec3 pos = glm::vec3(obj->mesh->pos->x, obj->mesh->pos->y, obj->mesh->pos->z);
                glm::vec3 scale = glm::vec3(obj->mesh->scale->x, obj->mesh->scale->y, obj->mesh->scale->z);
                glm::vec3 dir = glm::normalize(glm::vec3(obj->mesh->dir->x, obj->mesh->dir->y, obj->mesh->dir->z));
                glm::vec3 modelRight = glm::normalize(glm::cross(up, dir));
                glm::vec3 modelUp = glm::cross(dir, modelRight);

                if (dir.y == 1)
                {
                    modelUp = glm::vec3(1.0f, 0.0f, 0.0f);
                }

                glm::mat4 model = glm::mat4(1.0f);

                model = glm::translate(model, pos);

                model = (glm::lookAt(pos, dir + pos, modelUp));

                model = glm::scale(model, scale);

                float roll = *obj->mesh->roll * M_PI * 2;
                model = glm::rotate(model, roll, dir);

                int dirLightNumLoc = glGetUniformLocation(obj->shader->getID(), "DIR_LIGHTS");
                glUniform1ui(dirLightNumLoc, dirLights.size());
                int pointLightNumLoc = glGetUniformLocation(obj->shader->getID(), "POINT_LIGHTS");
                glUniform1ui(pointLightNumLoc, pointLights.size());
                int spotLightNumLoc = glGetUniformLocation(obj->shader->getID(), "SPOT_LIGHTS");
                glUniform1ui(spotLightNumLoc, spotLights.size());

                int projLoc = glGetUniformLocation(obj->shader->getID(), "projection");
                glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
                int matLoc = glGetUniformLocation(obj->shader->getID(), "model");
                glUniformMatrix4fv(matLoc, 1, GL_FALSE, glm::value_ptr(model));
                int viewLoc = glGetUniformLocation(obj->shader->getID(), "view");
                glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

                glDrawElements(GL_TRIANGLES, obj->mesh->getIndicSize(), GL_UNSIGNED_INT, (void *)0);
            }
        }
        _objectQueue.clear();
    }

    void OpenGLRenderEngine::addDirLight(DirLight dirLight)
    {
        dirLights.push_back(dirLight);
        dirSSBO->data.push_back(DirLightData(*dirLight.rot, *dirLight.color, *dirLight.luminance));
    }
    void OpenGLRenderEngine::removeDirLight(DirLight dirLight)
    {
        for (size_t i = 0; i < dirLights.size(); i++)
        {
            if (dirLights[i] == dirLight)
            {
                dirLights.erase(dirLights.begin() + i);
                dirSSBO->data.erase(dirSSBO->data.begin() + i);
                return;
            }
        }
    }
    void OpenGLRenderEngine::addPointLight(PointLight pointLight)
    {
        pointLights.push_back(pointLight);
        pointSSBO->data.push_back(PointLightData(*pointLight.pos, *pointLight.color, *pointLight.luminance));
    }
    void OpenGLRenderEngine::removePointLight(PointLight pointLight)
    {
        for (size_t i = 0; i < pointLights.size(); i++)
        {
            if (pointLights[i] == pointLight){
                pointLights.erase(pointLights.begin() + i);
                pointSSBO->data.erase(pointSSBO->data.begin() + i);
                return;
            }
        }
    }
    void OpenGLRenderEngine::addSpotLight(SpotLight spotLight)
    {
        spotLights.push_back(spotLight);
        spotSSBO->data.push_back(SpotLightData(*spotLight.pos, *spotLight.dir, *spotLight.color, *spotLight.innerRadius, *spotLight.radius, *spotLight.luminance));
    }
    void OpenGLRenderEngine::removeSpotLight(SpotLight spotLight)
    {
        for (size_t i = 0; i < spotLights.size(); i++)
        {
            if (spotLights[i] == spotLight){
                spotLights.erase(spotLights.begin() + i);
                spotSSBO->data.erase(spotSSBO->data.begin() + i);
                return;
            }
        }
    }

    bool OpenGLRenderEngine::destroyRenderer()
    {
        return true;
    }

    Renderer OpenGLRenderEngine::rendererType()
    {
        return OpenGL;
    }

    void OpenGLRenderEngine::setCamera(Cam cam)
    {
        this->camera = cam;
    }

} // namespace s_Renderer
