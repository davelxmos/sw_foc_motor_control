/*
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
 */

#include <xs1.h>
#include <assert.h>
#include <print.h>

#include "qei_common.h"

#ifndef _QEI_CLIENT_H_
#define _QEI_CLIENT_H_

/*****************************************************************************/
/** Returns New QEI parameters (speed, position, etc)
 * \param qei_param_s	// Reference to structure containing QEI parameters
 * \param c_qei	// Channel connecting QEI client & server
 */
void foc_qei_get_parameters( // Returns New QEI data (speed, position, etc)
	QEI_PARAM_TYP &qei_param_s,	// Reference to structure containing QEI parameters
	streaming chanend c_qei	// Channel connecting to QEI client & server
); // On return, qei_param_s is updated
/*****************************************************************************/

#endif /* _QEI_CLIENT_H_ */
