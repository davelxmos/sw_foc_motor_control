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

#ifndef _MAIN_H_
#define _MAIN_H_

#include <xs1.h>
#include <platform.h>

#include "app_global.h"
#include "shared_io.h"
#include "watchdog.h"
#include "inner_loop.h"
#include "adc_7265.h"
#include "hall_server.h"
#include "qei_server.h"
#include "pwm_server.h"

#if (USE_ETH)
#include "control_comms_eth.h"
#include "ethernet_board_support.h"
#endif // (USE_ETH)

#if (USE_CAN)
#include "control_comms_can.h"
#endif // (USE_CAN)

// Define where everything is
#define INTERFACE_TILE 0
#define MOTOR_TILE 1

/**  Default Filter Mode  1 == On */
#define ADC_FILTER 1

#endif /* _MAIN_H_ */
