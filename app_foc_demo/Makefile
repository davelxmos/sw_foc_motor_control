# The TARGET variable determines what target system the application is 
# compiled for. It either refers to an XN file in the source directories
# or a valid argument for the --target option when compiling.

TARGET = XP-MC-CTRL-L2

# The APP_NAME variable determines the name of the final .xe file. It should
# not include the .xe postfix. If left blank the name will default to 
# the project name

APP_NAME =

# The flags passed to xcc when building the application
# You can also set the following to override flags for a particular language:
#
#    XCC_XC_FLAGS, XCC_C_FLAGS, XCC_ASM_FLAGS, XCC_CPP_FLAGS
#
# If the variable XCC_MAP_FLAGS is set it overrides the flags passed to 
# xcc for the final link (mapping) stage.

XCC_FLAGS = -O3 -g -report -Wno-timing -fxscope 


# The USED_MODULES variable lists other module used by the application. 

USED_MODULES = module_foc_display module_foc_loop module_foc_qei module_foc_adc module_foc_hall module_foc_comms 
USED_MODULES += module_pwm_foc
USED_MODULES += module_xtcp module_ethernet_board_support module_can 
USED_MODULES += module_lib_uint_32 module_lib_uint_64

USE_XTCP_MAC_CUSTOM_FILTER = 1

XCC_FLAGS_Debug = $(XCC_FLAGS)
XCC_FLAGS_Release = $(XCC_FLAGS)


#=============================================================================
# The following part of the Makefile includes the common build infrastructure
# for compiling XMOS applications. You should not need to edit below here.

XMOS_MAKE_PATH ?= ../..
include $(XMOS_MAKE_PATH)/xcommon/module_xcommon/build/Makefile.common
