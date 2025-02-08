// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/AlgaeDislodger.h"
#include <frc/smartdashboard/SmartDashboard.h>

AlgaeDislodger::AlgaeDislodger() = default;

// This method will be called once per scheduler run
void AlgaeDislodger::Periodic() 
{
  frc::SmartDashboard::PutBoolean("ElevatorUpperSw",  GetUpperLimitSwitch() );
  frc::SmartDashboard::PutBoolean("ElevatorLowerSw",  GetLowerLimitSwitch() );
}

void AlgaeDislodger::StopMotor(void)
{
 m_algaeDislodgerMotor.Set(0.0);
}

double AlgaeDislodger::GetAlgaeDislodgerMotorPower(void)
 {
 return m_algaeDislodgerMotor.Get();
 }
void AlgaeDislodger::SetAlgaeDislodgerMotorPower(double power)
{
 m_algaeDislodgerMotor.Set(power);
}

bool AlgaeDislodger::GetLowerLimitSwitch(void)
{
 return m_algaeDislodgerMotor.GetReverseLimitSwitch().Get();
    //return false; 
}

bool AlgaeDislodger::GetUpperLimitSwitch(void)
{
return m_algaeDislodgerMotor.GetForwardLimitSwitch().Get();
    //return false; 
}






