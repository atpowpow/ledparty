// ledparty.cpp : Defines the entry point for the application.
//

#include "smc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include "stdafx.h"

void PrepareBuffers()
{
	ZeroMemory( m_SMCMessage, sizeof(m_SMCMessage) );
	ZeroMemory( m_SMCReturn, sizeof(m_SMCReturn) );
}

void SetLEDs(LEDState sTopLeft, LEDState sTopRight, LEDState sBottomLeft, LEDState sBottomRight)
{
	PrepareBuffers();
    m_SMCMessage[0] = 0x99;
    m_SMCMessage[1] = 0x01;

	m_SMCMessage[2] = ((unsigned char)(sTopLeft>>3) | (unsigned char)(sTopRight>>2) | (unsigned char)(sBottomLeft>>1) | (unsigned char)(sBottomRight));

	HalSendSMCMessage(m_SMCMessage, NULL);
}

void xbdelay(int milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

int main(){
	while(1){
		printf("PARTYYYY!!!\r");
		SetLEDs(GREEN, OFF, OFF, OFF);
		xbdelay(10);
		SetLEDs(OFF, GREEN, OFF, OFF);
		xbdelay(10);
		SetLEDs(OFF, OFF, GREEN, OFF);
		xbdelay(10);
		SetLEDs(OFF, OFF, OFF, GREEN);
		xbdelay(10);
	}
}