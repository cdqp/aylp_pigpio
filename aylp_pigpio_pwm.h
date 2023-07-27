// this plugin writes pwm signals using pigpio
#ifndef AYLP_PIGPIO_PWM_H_
#define AYLP_PIGPIO_PWM_H_

#include "anyloop.h"

struct aylp_pigpio_pwm_data {
	int *pins;		// array of gpio pins numbers to pwm
	size_t count;		// number of gpio pins to pwm
	size_t pwm_freq;	// frequency to pwm at [Hz]
};

// initialize pigpio device
int aylp_pigpio_pwm_init(struct aylp_device *self);

// update pwm duty cycle
int aylp_pigpio_pwm_process(struct aylp_device *self, struct aylp_state *state);

// close pigpio_pwm device when loop exits
int aylp_pigpio_pwm_close(struct aylp_device *self);

#endif

