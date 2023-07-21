Anyloop plugin for PWM via pigpio
=================================


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

