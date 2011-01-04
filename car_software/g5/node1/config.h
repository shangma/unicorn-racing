//******************************************************************************
//! @file $RCSfile: config.h,v $
//!
//! Copyright (c) 2007 Atmel.
//!
//! Use of this program is subject to Atmel's End User License Agreement.
//! Please read file license.txt for copyright notice.
//!
//! @brief Configuration file for the following project:
//!             - can_collector_node_example_gcc
//!
//! This file can be parsed by Doxygen for automatic documentation generation.
//! This file has been validated with AVRStudio-413528/WinAVR-20070122.
//!
//! @version $Revision: 3.20 $ $Name: jtellier $
//!
//! @todo
//! @bug
//******************************************************************************

#ifndef _CONFIG_H_
#define _CONFIG_H_

//_____ I N C L U D E S ________________________________________________________
#include "compiler.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "can_std/at90can_drv.h"

//_____ M A C R O S ____________________________________________________________

//_____ D E F I N I T I O N S __________________________________________________

    // -------------- MCU LIB CONFIGURATION
#define FOSC           110592        // 8 MHz External cristal
#define F_CPU          (FOSC*100) // Need for AVR GCC

    // -------------- CAN LIB CONFIGURATION
#define CAN_BAUDRATE   250        // in kBit
//#define CAN_BAUDRATE   CAN_AUTOBAUD

#define node1 0x80
#define node2 0x81
#define node3 0x82
#define node4 0x83

    // -------------- UART
#define BAUD0 19200 // ecu
#define BAUD1 115200  // Xbee

#define ECU 0
#define XBEE 1

/* --------------- TWI --------------- */
#define TWI_CLOCK 100000UL	/* 100 kHz */

//_____ D E C L A R A T I O N S ________________________________________________

#endif  // _CONFIG_H_


