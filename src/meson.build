
logger_srcs = files(
    'Logger/Logger.cpp'
)
renderer_srcs = files(
    'Renderer/OpenGLRenderEngine.cpp',
    'ThirdParty/glad/glad.c'
)
engine_srcs = files(
    'Game.cpp',
    'Context.cpp',
    'GWindow.cpp',
    #'Context.Linux.cpp',
    'main.cpp'
)
deps = dependency('glfw3')

build_srcs = logger_srcs + renderer_srcs + engine_srcs