// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Chute.h"

Chute::Chute() = default;

// This method will be called once per scheduler run
void Chute::Periodic() 
{

}
//bool   Chute::GetLimitSwitch(void)
//{
 
//}
void   Chute::StopMotor(void)
{
  m_pinMotor.Set(0.0);
}
void   Chute::SetPinMotorPower(double power)
{
  m_pinMotor.Set(power);
}
double Chute::GetPinMotorEncoder(void)
{
  return m_pinMotorEncoder.GetPosition();
}
bool   Chute::GetCoralDetectSensor(void)
{
  return false; //fix later
}



