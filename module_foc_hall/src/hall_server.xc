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

#include "hall_server.h"

/*****************************************************************************/
static void init_hall_data( // Initialise Hall data structure for one motor
	int motor_id,	// Unique motor id
	HALL_DATA_TYP &hall_data_s, // Reference to structure containing HALL data for one motor
	unsigned &hall_buf // Reference to buffer of  raw hall data for one motor
)
{
	hall_data_s.id = motor_id; // Set unique motor id
	hall_data_s.params.hall_val = 0;
	hall_buf = 0;

	return;
} // init_hall_data
/*****************************************************************************/
static void service_hall_input_pins( // Process new Hall data
	HALL_DATA_TYP &hall_data_s, // Reference to structure containing HALL data for one motor
	unsigned inp_pins // Set of raw data values on input port pins
)
{
	hall_data_s.inp_val = inp_pins & HALL_ALL_MASK; // Mask out active bits of Hall Sensor data

//MB~ TODO: Insert filter here

	hall_data_s.params.hall_val = hall_data_s.inp_val; // NB Filtering not yet implemented

	return;
} // service_hall_input_pins
/*****************************************************************************/
static void service_hall_client_request( // Send processed HALL data to client
	HALL_DATA_TYP &hall_data_s, // Reference to structure containing HALL data for one motor
	streaming chanend c_hall // Data channel to client (carries processed HALL data)
)
{
	c_hall <: hall_data_s.params;

	return;
} // service_hall_client_request
/*****************************************************************************/
void foc_hall_do_multiple( // Get Hall Sensor data from motor and send to client
	streaming chanend c_hall[], // Array of data channels to client (carries processed Hall data)
	port in p4_hall[]					// Array of input port (carries raw Hall motor data)
)
{
	HALL_DATA_TYP all_hall_data[NUMBER_OF_MOTORS]; // Array of structure containing HALL data for one motor
	unsigned hall_bufs[NUMBER_OF_MOTORS]; // odd and even buffers for raw hall data from input port pins for each motor
	int motor_cnt; // Counts number of motors
// int id = 1; //MB~ Dbg


	// Initialise Hall data for each motor
	for (motor_cnt=0; motor_cnt<NUMBER_OF_MOTORS; motor_cnt++)
	{ 
		init_hall_data( motor_cnt ,all_hall_data[motor_cnt] ,hall_bufs[motor_cnt] );
	} // for motor_cnt

	// Loop forever
	while (1) {
#pragma xta endpoint "hall_main_loop"
#pragma ordered // If multiple cases fire at same time, service top-most first
		select {
			// Service any change on input port pins
			case (int motor_id=0; motor_id<NUMBER_OF_MOTORS; motor_id++) p4_hall[motor_id] when pinsneq(hall_bufs[motor_id]) :> hall_bufs[motor_id] :
			{
#ifdef MB
if (motor_id)
{
	int tmp = 1 + (id << 1);

	xscope_probe_data( tmp ,( 100 * hall_bufs[motor_id] ) );
	id = 1 - id;
} // if (motor_id)
#endif //MB~
				service_hall_input_pins( all_hall_data[motor_id] ,hall_bufs[motor_id] );
			} // case
			break;

			// Service any client request for data
			case (int motor_id=0; motor_id<NUMBER_OF_MOTORS; motor_id++) c_hall[motor_id] :> int :
			{
				service_hall_client_request( all_hall_data[motor_id] ,c_hall[motor_id] );
			} // case
			break;
		} // select
	}	// while (1)

	return;
} // foc_hall_do_multiple
/*****************************************************************************/
