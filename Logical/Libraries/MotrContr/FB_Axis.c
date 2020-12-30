
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotrContr.h"
#ifdef __cplusplus
	};
#endif

void FB_Axis(struct FB_Axis* inst)
{
	if (inst->endswitch_a_reached || inst->endswitch_b_reached)
	{
		inst->pwm_value=0;
		inst->reset_error=1;
	}
	else
	{
		inst->pwm_value=inst->u/24.0*32767;//шим соответственно напряжению с регулятора
		inst->reset_error=0;
	}
	inst->speed=inst->u/24.0*6500.0;
}
