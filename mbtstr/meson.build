project(
  'mtbstr',
  'c',
  meson_version : '>= 1.4.2',
  default_options : [
    'c_args=-D_GNU_SOURCE',
    'c_std=c99',
    'debug=true',
    'optimization=0',
    'warning_level=3',
    'werror=true',
  ],
)

shared_library(
  'mbtstr',
  sources : [ 'mbt.c' ],
)
