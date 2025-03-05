// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Chute.h"
#include  <rev/config/SparkMaxConfig.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Robot.h"

Chute::Chute()
{
    


}

// This method will be called once per scheduler run
void Chute::Periodic() 
{

  const double uppower   = 0.2;
  const double downpower = 0.2;

  bool Xbtn = g_robotContainer.m_ctrl.X().Get();
  bool Ybtn = g_robotContainer.m_ctrl.Y().Get();


  if( Xbtn  ) 
  {
    SetPinMotorPower(uppower);
  }
  else if( Ybtn  )
  {
    SetPinMotorPower(downpower);
  }
  else
  {
    SetPinMotorPower(0.0);
  }


  frc::SmartDashboard::PutBoolean("ChutePinLimitSw",  GetLimitSwitch() );

}

void   Chute::StopMotor(void)
{
  m_pinMotor.Set(0.0);
}
void   Chute::SetPinMotorPower(double power)
{
  m_pinMotor.Set(power);
}

bool   Chute::GetCoralDetectSensor(void)
{
  return false; //fix later
}

bool Chute::GetLimitSwitch(void)
{
  return m_pinMotorLimitSwitch.Get();
}

