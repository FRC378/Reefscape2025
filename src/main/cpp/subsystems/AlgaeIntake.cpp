// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/AlgaeIntake.h"

AlgaeIntake::AlgaeIntake() = default;

// This method will be called once per scheduler run
void AlgaeIntake::Periodic() 
{

}
bool AlgaeIntake::GetUpperLimitSwitch(void)
{
 //return m_intakeMotor.GetForwardLimitSwitch().Get();
}
bool AlgaeIntake::GetLowerLimitSwitch(void)
{
 //return m_intakeMotor.GetReverseLimitSwitch().Get();
}
void AlgaeIntake::StopMotors(void)
{
    //m_intakeMotor.Set(0.0);
    m_swingMotor.Set(0.0);
}
void AlgaeIntake::SetSwingMotorPower(double power)
{
    m_swingMotor.Set(power);
}
void AlgaeIntake::SetIntakeMotorPower(double power)
{
    //m_intakeMotor.Set(power);
}
bool AlgaeIntake::GetAlgaeDetect(void)
{
    return false;   //fix later
}
double AlgaeIntake::GetSwingMotorEncoder(void)
{
    
}














