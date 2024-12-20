project('Sparks-Game-Engine', ['c', 'cpp'],
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'],
  license: 'MIT', 
  license_files: ['./LICENSE']
)

out = '/workspaces/Sparks-Game-Engine/install/Engine'
build_dir = 'builddir'
include = include_directories('include')

subdir('include')
install_headers(headers)

subdir('src')
engine = library('Sparks-Game-Engine',
           sources: build_srcs,
           install : true,
           

           )

subdir('test')
test('build sample project', executable('Sparks-Game-Engine-Test',
           sources: test_srcs,
           dependencies: dep,
           install : false
           ) 
)

