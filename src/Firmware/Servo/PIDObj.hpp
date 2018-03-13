#ifndef __SERVOHELPER
#define __SERVOHELPER

class PIDObj{
	public:
        PIDObj(int tcP, int tcI, int tcD, int tintegralActiveZone, int tmaxIntAdjust);  
		int pidCalc(int desiredPos, int position);
        int angleToServoUnit(int angle, int dMax, int dMin, int unitsPerCircle);
	private:
		int integralTerm();
		int derivativeTerm();
		int proportionalTerm();

		int lastError = 0;
		int error;
		int cP;
		int cI;
		int cD;
        int integralActiveZone;
        int errorS = 0;
        int maxIntAdjust;
};

#endif
