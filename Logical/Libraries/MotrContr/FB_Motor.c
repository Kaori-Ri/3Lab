
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotrContr.h"
#ifdef __cplusplus
	};
#endif

void FB_Motor(struct FB_Motor* inst)
{
	inst->integrator.in = (inst->u / inst->ke - inst->w) * inst->dt / inst->Tm; //integr's in (incoming signal u multipled by 1/ke subtracting w then multipled by dt/Tm)
	
	FB_Integrator(&(inst->integrator));			
	inst->w = inst->integrator.out;				
	
	inst->integrator.in = inst->w * inst->dt;	
	
	//inst->integrator.out = inst->phi;
	
	FB_Integrator(&(inst->integrator));			
	
	inst->phi = inst->integrator.out; 			
}
