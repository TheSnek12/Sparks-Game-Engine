
logger_srcs = files(
    'Logger/Logger.cpp'
)
renderer_srcs = files(
    'Renderer/OpenGL/OpenGLRenderEngine.cpp',
    'Renderer/OpenGL/OpenGLMesh.cpp',
    'Renderer/OpenGL/OpenGLShader.cpp',
    'Renderer/OpenGL/OpenGLTexture.cpp',
    'Renderer/Shader.cpp',
    'Renderer/Texture.cpp',
    'Renderer/Mesh.cpp',
    'ThirdParty/glad/glad.c'
)
audio_srcs = files(
    'Audio/AL/ALAudio.cpp',
)
network_srcs = files(
    'Networking/RemoteGame.cpp',
    'Networking/GameHost.cpp'
)
engine_srcs = files(
    'GWindow.cpp',
    'Scriptables/RenderMesh.cpp',
    'Scriptables/DirectionalLight.cpp',
    'Scriptables/PointLight.cpp',
    'Scriptables/SpotLight.cpp',
    'Window.cpp',
    'Scriptables/AudioSource.cpp',
    'Game.cpp',
    'Scene.cpp',
    'GameObject.cpp',
    'Context.cpp',
    #'Context.Linux.cpp',
    'main.cpp'
)
deps = [
    dependency('glfw3'),
    dependency('libenet'),
    dependency('openal'),
    dependency('glm'),
    dependency('assimp')
]

build_srcs = logger_srcs + renderer_srcs + engine_srcs + audio_srcs + network_srcs