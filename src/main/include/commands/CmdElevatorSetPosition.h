// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

class CmdElevatorSetPosition
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdElevatorSetPosition> {
 public:
  CmdElevatorSetPosition( double position );

  void Initialize() override;

  private:
  double m_position;
};
