#include "anyloop.h"
#include "logging.h"
#include "xalloc.h"
#include "aylp_pigpio_pwm.h"


int aylp_pigpio_init(struct aylp_device *self)
{
	int err;
	self->device_data = xcalloc(1, sizeof(struct aylp_pigpio_data));
	struct aylp_pigpio_data *data = self->device_data;
	// attach methods
	self->process = &aylp_pigpio_process;
	self->close = &aylp_pigpio_close;

	json_object *pwm_pins_jarr = 0;
	json_object *clock_pins_jarr = 0;
	data->pwm_count = 0;
	data->clock_count = 0;
	// parse the params json into our data struct
	if (!self->params) {
		log_error("No params object found.");
		return -1;
	}
	json_object_object_foreach(self->params, key, val) {
		if (key[0] == '_') {
			// keys starting with _ are comments
		} else if (!strcmp(key, "pwm_pins")) {
			// TODO
		} else if (!strcmp(key, "clock_pins")) {
			// TODO
		} else if (!strcmp(key, "pwm_count")) {
			data->pwm_count = json_object_get_uint64(val);
			log_trace("pwm_count = %llu", data->pwm_count);
		} else if (!strcmp(key, "clock_count")) {
			data->clock_count = json_object_get_uint64(val);
			log_trace("clock_count = %llu", data->clock_count);
		} else {
			log_warn("Unknown parameter \"%s\"", key);
		}
	}
	// enforce required params
	if (!pwm_pins_jarr || !data->pwm_count) {
		log_error("You must provide pwm_pins and pwm_count params.");
		return -1;
	}

	// TODO: set up communication to pigpiod

	// set types and units
	self->type_in = AYLP_T_VECTOR;
	self->units_in = AYLP_U_MINMAX;
	self->type_out = 0;
	self->units_out = 0;
	return 0;
}


int aylp_pigpio_process(struct aylp_device *self, struct aylp_state *state)
{
	UNUSED(state);
	struct aylp_pigpio_data *data = self->device_data;
	// TODO: communicate to pigpiod that we need to pwm
	return 0;
}


int aylp_pigpio_close(struct aylp_device *self)
{
	struct aylp_pigpio_data *data = self->device_data;
	xfree(data->gpio_pins);
	xfree(self->device_data);
	return 0;
}

