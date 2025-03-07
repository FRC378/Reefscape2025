// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveForceTurnAngle.h"
#include "Robot.h"

CmdDriveForceTurnAngle::CmdDriveForceTurnAngle( double angle) 
{
  m_angle = angle;
  AddRequirements({ &g_robotContainer.m_drivetrain });
}

void CmdDriveForceTurnAngle::Initialize() 
{
  m_timer.Reset();
  m_timer.Start();
  g_robotContainer.m_drivetrain.ForceAllTurnAngle(m_angle);
  cout << "CmdDriveForceTurnAngle " << m_angle << endl;
}

void CmdDriveForceTurnAngle::Execute() {}

void CmdDriveForceTurnAngle::End(bool interrupted) 
{
  //g_robotContainer.m_drivetrain.Stop();
}


bool CmdDriveForceTurnAngle::IsFinished() 
{
  return true; //Immediate if using ResetHeadings
  // if ( m_timer.HasElapsed( units::second_t( 2.0 )  ) )
  // {
  //   m_timer.Stop();
  //   return true;
  // }

  // return false;
}
