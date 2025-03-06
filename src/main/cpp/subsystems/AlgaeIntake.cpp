// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/AlgaeIntake.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

AlgaeIntake::AlgaeIntake()
{

  frc::SmartDashboard::PutNumber("AlgaeIntake_inPwr",   0.5 );
  frc::SmartDashboard::PutNumber("AlgaeIntake_outPwr",  0.5 );
}

// This method will be called once per scheduler run
void AlgaeIntake::Periodic() 
{

  const double deadband  = 0.5;
  const double uppower   = 0.9;
  const double downpower = 0.9;
  double axis = g_robotContainer.m_ctrl.GetLeftX(); //Positive is Left - DOWN
  if( (axis > deadband)  ) 
  {
    SetSwingMotorPower(downpower);
  }
  else if( (axis < -deadband)  )
  {
    SetSwingMotorPower(-uppower);
  }
  else
  {
    SetSwingMotorPower(0.0);
  }

  bool Abtn = g_robotContainer.m_ctrl.A().Get();
  bool Bbtn = g_robotContainer.m_ctrl.B().Get();

  double inPwr  = frc::SmartDashboard::GetNumber("AlgaeIntake_inPwr",  0.0 );
  double outPwr = frc::SmartDashboard::GetNumber("AlgaeIntake_outPwr", 0.0 );

  if( Abtn  ) 
  {
    SetIntakeMotorPower(inPwr);
  }
  else if( Bbtn  )
  {
    SetIntakeMotorPower(-outPwr);
  }
  else
  {
    SetIntakeMotorPower(0.0);
  }


}



bool AlgaeIntake::GetUpperLimitSwitch(void)
{
 //return m_intakeMotor.GetForwardLimitSwitch().Get();
 return false;
}
bool AlgaeIntake::GetLowerLimitSwitch(void)
{
 //return m_intakeMotor.GetReverseLimitSwitch().Get();
 return false;
}
void AlgaeIntake::StopMotors(void)
{
    m_intakeMotor.Set(0.0);
    m_swingMotor.Set(0.0);
}
void AlgaeIntake::SetSwingMotorPower(double power)
{
    m_swingMotor.Set(power);
}
void AlgaeIntake::SetIntakeMotorPower(double power)
{
    m_intakeMotor.Set(power);
}
bool AlgaeIntake::GetAlgaeDetect(void)
{
    return false;   //fix later
}















