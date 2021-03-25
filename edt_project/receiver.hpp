#pragma once

void SetupReceiver();
void ReadReceiver(AxisData& remoteControllerData);
void ReadElevator(float& elevatorData);
bool CheckReceiver();
