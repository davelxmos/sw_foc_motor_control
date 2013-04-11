/**
 * The copyrights, all other intellectual and industrial 
 * property rights are retained by XMOS and/or its licensors. 
 * Terms and conditions covering the use of this code can
 * be found in the Xmos End User License Agreement.
 *
 * Copyright XMOS Ltd 2013
 *
 * In the case where this code is a modification of existing code
 * under a separate license, the separate license terms are shown
 * below. The modifications to the code are still covered by the 
 * copyright notice above.
 **/                                   
#ifndef _APP_GLOBAL_H_
#define _APP_GLOBAL_H_

/** Define this to include XSCOPE support */
#define USE_XSCOPE 1

#if (USE_XSCOPE)
#include <xscope.h>
#endif // (USE_XSCOPE)

/** Define this to switch on error checks */
#define CHECK_ERRORS 1

/**  Default Filter Mode  1 == On */
#define ADC_FILTER 1

/** Define the number of motors */
#define NUMBER_OF_MOTORS 2


// Motor specific definitions ... (Currently Set for LDO Motors)

/** Define the number of pole-pairs in motor */
#define NUM_POLE_PAIRS 4

/** Define the number of different QEI sensor positions per pole-pair */
#define QEI_PER_POLE 256

/** Define Maximum specified motor speed. WARNING: Safety critical */
#define MAX_SPEC_RPM 4000

#define QEI_PER_REV (QEI_PER_POLE * NUM_POLE_PAIRS)


// PWM specific definitions ...

// If locked, the ADC sampling will occur in the middle of the  switching sequence.
// It is triggered over a channel. Set this define to 0 to disable this feature
/** Define if ADC sampling is locked to PWM switching */
#define LOCK_ADC_TO_PWM 1

/** Define if Shared Memory is used to transfer PWM data from Client to Server */
#define PWM_SHARED_MEM 0 // 0: Use c_pwm channel for pwm data transfer


// Communications specific definitions ...

/** Define the port for the control app to connect to */
#define TCP_CONTROL_PORT 9595

/** Define this to enable the Ethernet interface */
#define USE_ETH 1

/** Define this to enable the CAN interface */
#define USE_CAN 0

// Check that both interfaces are not defined
#if (USE_CAN && USE_ETH)
	#error Both CAN and Ethernet are enabled.
#endif

#endif /* _APP_GLOBAL_H_ */