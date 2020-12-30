
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	gAxis_X_EncIf.iLifeCnt++; 
	gAxis_X_DiDoIf.iLifeCntDriveEnable++;
	gAxis_X_DiDoIf.iLifeCntDriveReady++; 
	gAxis_X_DiDoIf.iLifeCntNegHwEnd++; 
	gAxis_X_DiDoIf.iLifeCntPosHwEnd++; 
	gAxis_X_DiDoIf.iLifeCntReference++; 
	gAxis_X_DrvIf.iLifeCnt++; 
	
	gAxis_X_EncIf.iActTime = (INT)AsIOTimeCyclicStart();
	gAxis_X_EncIf.iActPos = axis_X.counter;
	
	gAxis_X_iPosHwEnd = axis_X.endswitch_b_reached;
	gAxis_X_iNegHwEnd = axis_X.endswitch_a_reached;
	
	if(coil_powered)
		coil_pwm_value = 32767;
	else
		coil_pwm_value = 0;
	//fb_controller.e = gAxis_X_DrvIf.oSetPos*6500.0/32767 - axis_X.speed; //6500.0 максимльня скорость в метках в секунду
	//FB_Regulator(&fb_controller); // передать значение в регулятор
	//axis_X.u = fb_controller.u;
	axis_X.u = 12;
	FB_Axis(&axis_X);
}
