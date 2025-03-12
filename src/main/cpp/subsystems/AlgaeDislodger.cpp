// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/AlgaeDislodger.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <rev/config/SparkMaxConfig.h>
#include "Robot.h"

AlgaeDislodger::AlgaeDislodger()
{
  m_manualControl = false;
}

// This method will be called once per scheduler run
void AlgaeDislodger::Periodic() 
{

  const double deadband  = 0.5;
  const double uppower   = 0.5;
  const double downpower = 0.5;
  double axis = g_robotContainer.m_ctrl.GetRightX(); //Positive is Left - DOWN
  if( (axis > deadband)  ) 
  {
    SetAlgaeDislodgerMotorPower(downpower);
    m_manualControl = true;
  }
  else if( (axis < -deadband)  )
  {
    SetAlgaeDislodgerMotorPower(-uppower);
    m_manualControl = true;
  }
  else
  {
    if( m_manualControl)
    {
      SetAlgaeDislodgerMotorPower(0.0);
      m_manualControl = false;
    }
    
  }
}

void AlgaeDislodger::StopMotor(void)
{
 m_algaedislodger.Set(0.0);
}

double AlgaeDislodger::GetAlgaeDislodgerMotorPower(void)
 {
 return m_algaedislodger.Get();
 }
void AlgaeDislodger::SetAlgaeDislodgerMotorPower(double power)
{
 m_algaedislodger.Set(power);

  
}



