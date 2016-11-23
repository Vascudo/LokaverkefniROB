

void beeptest()
{
	while(vexRT[Btn8L] == 0)
	{
		for (int i = 1; i < 3; i++)
		{
			motor[rightMotor] = 127;		  // Motor on port2 is run at full (127) power forward
			motor[leftMotor]  = 127;		  // Motor on port3 is run at full (127) power forward
			wait1Msec(700 * i);
			motor[rightMotor] = -127;		  // Motor on port2 is run at full (127) power forward
			motor[leftMotor]  = -127;		  // Motor on port3 is run at full (127) power forward
			wait1Msec(700 * i);
		}
	}

}
