
void verk2()
{
		while((SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1) && vexRT[Btn8L] == 0)
	  {
	    motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
	    motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2

	    if(vexRT[Btn6U] == 1)//Makes arm go forward//
	    {
	      motor[armMotor] = -63;
	    }
	    else if(vexRT[Btn6D] == 1)//Makes arm go backwards//
	    {
	      motor[armMotor] = 63;
	    }

	    if(vexRT[Btn5U] == 1) //Makes claw open//
	    {
	      motor[clawMotor] = -63;
	    }
	    else if(vexRT[Btn5D] == 1)//Makes claw close//
	    {
	      motor[clawMotor] = 63;
	    }

	    else
	    {
	      motor[armMotor] = 0;//Makes arm stop when not pressing button//
	      motor[clawMotor] = 0;//Makes claw stop when not pressing button//
	    }

	    if(vexRT[Btn8R])//Brakes by stopping motors//
	    {
	    	motor[rightMotor] = 0;
	    	motor[leftMotor] = 0;
	    }
	  }

}
