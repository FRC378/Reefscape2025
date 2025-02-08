// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdElevatorDefault.h"
#include "Robot.h"

CmdElevatorDefault::CmdElevatorDefault()
{
  
  AddRequirements( &g_robotContainer.m_elevator);
}


void CmdElevatorDefault::Initialize() 
{
  std:: cout << "Elevator default started" << std::endl;
  m_manualElevatorEnable = false;
}


void CmdElevatorDefault::Execute() 
{

  //*******  MANUAL ELEVATOR CONTROL   *******

  const double DEADBAND = 0.5;

  double axis = -g_robotContainer.m_ctrl.GetLeftY();

  if(  (axis > DEADBAND) && !g_robotContainer.m_elevator.GetUpperLimitSwitch() )
  {
    g_robotContainer.m_elevator.SetPower( (axis-DEADBAND) * 0.15  );
    m_manualElevatorEnable = true;
  }
  else if ( (axis < -DEADBAND) && !g_robotContainer.m_elevator.GetLowerLimitSwitch() )
  {
    g_robotContainer.m_elevator.SetPower( (axis+DEADBAND) * 0.15  );
    m_manualElevatorEnable = true;
  }
  else if(m_manualElevatorEnable)
  { 
    g_robotContainer.m_elevator.Stop();                                                     // Can we do this?  
  //g_robotContainer.m_elevator.SetPosition(  g_robotContainer.m_elevator.GetPosition() );  // Or do we need to do this?

    m_manualElevatorEnable = false;
  }

}


void CmdElevatorDefault::End(bool interrupted) 
{

}


bool CmdElevatorDefault::IsFinished() 
{
  return false;
}
