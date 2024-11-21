project(
  'my_torrent',
  'c',
  meson_version : '>= 1.1.0', # meson minimum version
  version : '1.0.0', # project version
  default_options : [
    'c_args=-D_GNU_SOURCE',
    'c_std=c99', # -std=c99
    'debug=true', # -g
    'optimization=0', # -O0
    'warning_level=3', # -Wall -Wextra -Wpedantic
    'werror=true',
    'b_sanitize=address,undefined',
  ],
)

libs = [ include_directories('libs') ]

mbtutils_lib = shared_library(
  'mbtutils',
  sources : [ 'src/utils.c' ],
  include_directories : explib_inc + [ include_directories('src') ],
  install : true,
)

mbtbe_lib = shared_library(
  'mbtbe',
  sources : [ 'src/utils.c' ],
  include_directories : explib_inc + [ include_directories('src') ],
  install : true,
)

mbtfile_lib = shared_library(
  'mbtfile',
  sources : [ 'src/utils.c' ],
  include_directories : explib_inc + [ include_directories('src') ],
  install : true,
)

mbtnet_lib = shared_library(
  'mbtnet',
  sources : [ 'src/utils.c' ],
  include_directories : explib_inc + [ include_directories('src') ],
  install : true,
)

executable(
  'mbt',
  sources : [ 'src/main.c' ],
  include_directories : [ include_directories('src')] + libs,
  install : true,
)
