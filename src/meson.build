
logger_srcs = files(
    'Logger/Logger.cpp'
)
renderer_srcs = files(
    'Renderer/OpenGL/OpenGLRenderEngine.cpp',
    'Renderer/OpenGL/OpenGLMesh.cpp',
    'Renderer/OpenGL/OpenGLShader.cpp',
    'Renderer/Shader.cpp',
    'Renderer/Texture.cpp',
    'Renderer/Mesh.cpp',
    'ThirdParty/glad/glad.c'
)
engine_srcs = files(
    'GWindow.cpp',
    'Window.cpp',
    'Game.cpp',
    'Context.cpp',
    #'Context.Linux.cpp',
    'main.cpp'
)
deps = [
    dependency('glfw3'),
    dependency('glm'),
    dependency('assimp')
]

build_srcs = logger_srcs + renderer_srcs + engine_srcs