/*
 * ******************************************************************************
 *  Copyright (c) 2013-2014 CriativaSoft (www.criativasoft.com.br)
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 *
 *  Contributors:
 *  Ricardo JL Rufino - Initial API and Implementation
 * *****************************************************************************
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <inttypes.h>


namespace CommandType {
	enum CommandType {
		ON_OFF = 1,     // Indicates that the values are 0 or 1 (HIGH or LOW)
		ANALOG = 2,
		ANALOG_REPORT = 3,
		GPIO_DIGITAL = 4,   // Commands sent directly to the pins (digitalWrite)
		GPIO_ANALOG = 5,   //  Commands sent directly to the pins (analogWrite)
		PWM = 6,
		INFRA_RED = 7,
		DEVICE_COMMAND_RESPONSE = 10, // Response to commands like: ON_OFF, POWER_LEVEL, INFRA RED
		PING = 20,
		PING_RESPONSE = 21,
		MEMORY_REPORT = 22, //  Reports the current and maximum Memory.
		CPU_TEMPERATURE_REPORT = 23,
		CPU_USAGE_REPORT = 24,
		GET_DEVICES = 30,
		GET_DEVICES_RESPONSE = 31,
		USER_COMMAND = 99
	};
}

namespace ResponseStatus {
	enum ResponseStatus {
		SUCCESS = 200,
		NOT_FOUND = 404,
		BAD_REQUEST = 400,
		UNAUTHORIZED = 401,
		PERMISSION_DENIED = 550,
		FORBIDDEN = 403,
		INTERNAL_ERROR = 500,
		NOT_IMPLEMENTED = 501,
		BUFFER_OVERFLOW = 502
	};
}

/*namespace SersorType {
	enum SersorType {
		SWITCH = 1, TOOGLE = 2, INFRA_RED = 3,
	};
}*/

struct Command {

	static const uint8_t START_BIT = '/';
	static const uint8_t SEPARATOR = '/';
	static const uint8_t ARRAY_SEPARATOR = ',';
	static const uint8_t ACK_BIT = '\r';

	Command():type(0),id(0),deviceID(0),value(0),length(0){ }

	uint8_t type; // values of CommandType
	uint8_t id;
	uint8_t deviceID;
	unsigned long value;
	size_t length;


	static bool isDeviceCommand( uint8_t type ) {
		if (type == 0) return false;

		switch (type) {
		case CommandType::ON_OFF: return true;
		case CommandType::ANALOG: return true;
		case CommandType::ANALOG_REPORT: return true;
		default:
			break;
		}
		return false;
	}
};

#endif /* HEADER */

