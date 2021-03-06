/**
 * \file adc_client.h
 *
 * The copyrights, all other intellectual and industrial 
 * property rights are retained by XMOS and/or its licensors. 
 * Terms and conditions covering the use of this code can
 * be found in the Xmos End User License Agreement.
 *
 * Copyright XMOS Ltd 2011
 *
 * In the case where this code is a modification of existing code
 * under a separate license, the separate license terms are shown
 * below. The modifications to the code are still covered by the 
 * copyright notice above.
 *
 **/

#ifndef _ADC_CLIENT_H_
#define _ADC_CLIENT_H_

#include <xs1.h>
#include <print.h>
#include <assert.h>

#include "app_global.h"
#include "adc_common.h"

/*****************************************************************************/
/** Get 12-bit ADC values and convert to signed 32-bit integer
 * \param adc_param_s // Structure containing ADC parameters
 * \param c_adc  // channel connecting ADC client and server
 */
void foc_adc_get_parameters( // Get 12-bit ADC values and convert to signed 32-bit integer
	ADC_PARAM_TYP &adc_param_s, // Structure containing ADC parameters
	streaming chanend c_adc
);
/*****************************************************************************/
#endif // _ADC_CLIENT_H_
