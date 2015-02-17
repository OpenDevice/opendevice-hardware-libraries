/*
 * *****************************************************************************
 * See tutorial: https://opendevice.atlassian.net/wiki/display/DOC/A.+First+Steps+with+OpenDevice
 * This example code is in the public domain.
 * *****************************************************************************
 */

#include <DeviceConnection.h>
#include <OpenDevice.h>

// Configs for Wiznet shieds
//#include <SPI.h>
//#include <Ethernet.h>
//#include <TcpConnection.h>
//TcpConnection deviceConnection(8081);

// Configs for ENC28J60 shieds/modules
#include <UIPEthernet.h>
#include <TcpConnectionENC28.h>
TcpConnectionENC28 deviceConnection(8081);


void setup(){
    OpenDevice::debugMode = true;
    OpenDevice::debugTarget = 0;
    
    Serial.begin(9600);  
    // while (!Serial){delay(1);} // uncomment if using Leonardo
   
    OpenDevice::addDevice(13, Device::DIGITAL); // ID:1
    
    OpenDevice::begin(deviceConnection);			
    OpenDevice::debug("Started!");
         
}

void loop(){
	
    OpenDevice::loop();

}
