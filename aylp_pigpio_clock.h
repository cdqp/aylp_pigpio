// this plugin writes clock signals using pigpio
#ifndef AYLP_PIGPIO_CLOCK_H_
#define AYLP_PIGPIO_CLOCK_H_

#include "anyloop.h"

// initialize pigpio_clock device
int aylp_pigpio_clock_init(struct aylp_device *self);

// close pigpio_clock device when loop exits
int aylp_pigpio_clock_close(struct aylp_device *self);

#endif

