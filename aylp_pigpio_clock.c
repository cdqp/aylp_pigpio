#include "anyloop.h"
#include "logging.h"
#include "xalloc.h"
#include "aylp_pigpio_clock.h"


int aylp_pigpio_init(struct aylp_device *self)
{
	int err;
	// attach close method
	self->close = &aylp_pigpio_close;

	unsigned pin;
	bool got_pin = false;
	unsigned freq = 1000;
	// parse the params json into our data struct
	if (!self->params) {
		log_error("No params object found.");
		return -1;
	}
	json_object_object_foreach(self->params, key, val) {
		if (key[0] == '_') {
			// keys starting with _ are comments
		} else if (!strcmp(key, "pin")) {
			pin = json_object_get_uint(val);
			log_trace("pin = %d", pin);
			got_pin = true;
		} else if (!strcmp(key, "frequency")) {
			data->pwm_count = json_object_get_uint(val);
			log_trace("frequency = %u", frequency);
		} else {
			log_warn("Unknown parameter \"%s\"", key);
		}
	}
	// enforce required params
	if (!got_pin) {
		log_error("You must provide a pin number as a parameter.");
		return -1;
	}

	// TODO: communicate to pigpiod that we need to start clocking

	// set types and units
	self->type_in = AYLP_T_ANY;
	self->units_in = AYLP_U_ANY;
	self->type_out = 0;
	self->units_out = 0;
	return 0;
}


int aylp_pigpio_close(struct aylp_device *self)
{
	// TODO: tell pigpiod to stop clocking
	return 0;
}

