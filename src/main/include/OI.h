#pragma once

#include <frc/WPILib.h>

class OI
{
	public:
		OI();
		double GetThrottleAxis(); //returns the axis to drive the robot
		double GetStrafeAxis(); //returns the axis to strafe the robot
		double GetTurnAxis(); //returns the axis to turn the robot
		double GetLiftAxis(); //returns the axis for lift adjustment
	private:
		//private functions
		double DeadZone(double axisVal);
		double SteeringDeadZone(double uval);
		double RampingDeadZone(double uval);
		double InputShape(double userValue);

		//create joystick objects
		std::shared_ptr<frc::Joystick> drive_stick_throttle;
		std::shared_ptr<frc::Joystick> drive_stick_strafe;
		std::shared_ptr<frc::Joystick> steer_stick_turn;
		std::shared_ptr<frc::Joystick> steer_stick_lift;
		std::shared_ptr<frc::Joystick> l_buttons; //left set of buttons
		std::shared_ptr<frc::Joystick> r_buttons; //right set of buttons

		//create buttons for control
		//lift
		frc::JoystickButton * button_lift_lh_front; //low hatch front
		frc::JoystickButton * button_lift_mh_front; //mid hatch front
		frc::JoystickButton * button_lift_hh_front; //high hatch front
		frc::JoystickButton * button_lift_lc_front; //low cargo front
		frc::JoystickButton * button_lift_mc_front; //mid cargo front
		frc::JoystickButton * button_lift_hc_front; //high cargo front
		frc::JoystickButton * button_lift_lh_back; //low hatch back
		frc::JoystickButton * button_lift_mh_back; //mid hatch back
		frc::JoystickButton * button_lift_hh_back; //high hatch back
		frc::JoystickButton * button_lift_lc_back; //low cargo back
		frc::JoystickButton * button_lift_mc_back; //mid cargo back
		frc::JoystickButton * button_lift_hc_back; //high cargo back
		//claw
		frc::JoystickButton * button_claw_fo; //full open
		frc::JoystickButton * button_claw_cc; //capture cargo
		frc::JoystickButton * button_claw_fc; //full closed
		frc::JoystickButton * button_claw_ch; //capture hatch
		frc::JoystickButton * button_claw_ehr; //emergency hatch release (full close + safe zone)
		//other
		frc::JoystickButton * button_cam_aa; //aim assist
		frc::JoystickButton * button_end_up; //extend both sides
		frc::JoystickButton * button_end_dn; //retract close side
		frc::JoystickButton * button_end_dnall; //retract both sides
		frc::JoystickButton * button_light_mu; //light mode up
		frc::JoystickButton * button_light_md; //light mode down
};
