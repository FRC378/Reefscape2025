// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Climber.h"
#include <rev/config/SparkMaxConfig.h>


Climber::Climber() 
{
    //SparkMaxConfigurator
    rev::spark::SparkMaxConfig motorConfig;

    motorConfig
        .SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kBrake)
        .SmartCurrentLimit(50)
        .Inverted(false)
        .OpenLoopRampRate(0.3);

    m_climber.Configure( motorConfig,
                rev::spark::SparkMax::ResetMode::kResetSafeParameters,
                rev::spark::SparkMax::PersistMode::kPersistParameters);
}

// This method will be called once per scheduler run
void Climber::Periodic() 
{

}

 bool Climber::GetUpperLimitSwitch(void)
 {
    return m_climber.GetForwardLimitSwitch().Get();
    //return false;
 }
 bool Climber::GetLowerLimitSwitch(void)
 {
    return m_climber.GetReverseLimitSwitch().Get();
    //return false; 
 }
 void Climber::StopMotor(void)
 {
    m_climber.Set(0.0);
 }
 void Climber::SetMotorPower(double power)
 {
    m_climber.Set(power);
 }
 double Climber::GetMotorPower(void)
 {
    return m_climber.Get();
 }

