// Do not remove the include below
#include "main.h"
#include "LightControl.h"
#include "SerialDebug.h"

LightControl* lightControl = 0;

void setup() {
	SerialDebugger.begin(9600);
	SerialDebugger.enable(NOTIFICATION);
	SerialDebugger.enable(ERROR);
	SerialDebugger.enable(WARNING);
	SerialDebugger.enable(STATUSUPDATE);
	char buffer[50];
	sprintf(buffer, "Starte:", 0);
	SerialDebugger.debug(STATUSUPDATE, "onLoop", buffer);

	lightControl = new LightControl();
	lightControl->testSpotlight();
}

void loop() {

	lightControl->onLoop();
}
