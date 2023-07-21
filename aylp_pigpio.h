// this plugin writes pwm signals using pigpio
#ifndef AYLP_PIGPIO_H_
#define AYLP_PIGPIO_H_

#include "anyloop.h"

struct aylp_pigpio_data {
	int *pwm_pins;		// array of gpio pins numbers to pwm
	size_t pwm_count;	// number of gpio pins to pwm
	int *clock_pins;	// array of gpio pins to clock
	size_t clock_count;	// number of gpio pins to clock
	size_t clock_freq;	// frequency to clock at [Hz]
};

// initialize pigpio device
int aylp_pigpio_init(struct aylp_device *self);

// busy-wait for frame
int aylp_pigpio_process(struct aylp_device *self, struct aylp_state *state);

// close pigpio device when loop exits
int aylp_pigpio_close(struct aylp_device *self);

#endif

