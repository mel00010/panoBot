#ifndef __SERVOHELPER
#define __SERVOHELPER

class PIDObj{
	public:
		double pidCalc(double desiredPos);
	private:
		double integralTermH();
		double derivativeTermH();
		double proportionalTermH();

		double integralTermV();
		double derivativeTermV();
		double proportionalTermV();

		double lastErrorV = 0;
		double lastErrorH = 0;
		double errorV;
		double errorH;
		double cP;
		double cI;
		double cD;
        double integralActiveZone;
        double errorSH;
        double errorSV;
        double maxIntAdjust;
};

#endif
