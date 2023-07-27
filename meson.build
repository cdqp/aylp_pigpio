project(
	'aylp_pigpio',
	'c',
	default_options: ['c_std=gnu17', 'warning_level=3', 'optimization=3']
)

incdir = include_directories(['libaylp'])

c = meson.get_compiler('c')
pigpio_dep = c.find_library('pigpio', required: true)
gsl_dep = dependency('gsl')
json_dep = dependency('json-c')
deps = [pigpio_dep, gsl_dep, json_dep]

shared_library('aylp_pigpio_pwm', 'aylp_pigpio_pwm.c',
	name_prefix: '',
	install: true,
	dependencies: deps,
	include_directories: incdir,
	override_options: 'b_lundef=false'
)

shared_library('aylp_pigpio_clock', 'aylp_pigpio_clock.c',
	name_prefix: '',
	install: true,
	dependencies: deps,
	include_directories: incdir,
	override_options: 'b_lundef=false'
)

