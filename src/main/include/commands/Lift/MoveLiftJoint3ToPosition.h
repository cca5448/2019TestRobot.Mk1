#pragma once

#include "frc/commands/Command.h"

class MoveLiftJoint3ToPosition: public frc::Command
{
    private:
        double m_TARGET_POS;
	public:
		MoveLiftJoint3ToPosition(double pos);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};