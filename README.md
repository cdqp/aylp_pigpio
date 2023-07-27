Anyloop plugin for PWM via pigpio
=================================

Note: this plugin is not usable or properly tested yet. It is just a sketch for
now.

There are two plugins in this repository: `aylp_pigpio_pwm`, which applies pulse
width modulation, and `aylp_pigpio_clock`, which simply clocks a pin at a
certain frequency.

You will need to start the `pigpiod` daemon before running this plugin.


libaylp dependency
------------------

Symlink or copy the `libaylp` directory from anyloop to `libaylp`. For example:

```sh
ln -s $HOME/git/anyloop/libaylp libaylp
```


pigpio dependency
-----------------

Install [pigpio](https://github.com/joan2937/pigpio) normally.


Building
--------

Use meson:

```sh
meson setup build
meson compile -C build
```

