#pragma once

void SetupReceiver();
void ReadReceiver(AxisData& remoteControllerData);
void ReadAux(float& auxData);
bool CheckReceiver();
