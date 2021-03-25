#pragma once

void SetupReceiver();
void ReadReceiver(AxisData& remoteControllerData);
void ReadThrottle(float& throttleData);
bool CheckReceiver();
