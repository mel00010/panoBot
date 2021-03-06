#include "../../Firmware-Old/Servo/PIDObj.hpp"

PIDObj::PIDObj(int tcP, int tcI, int tcD, int tintegralActiveZone, int tmaxIntAdjust){
    cP = tcP;
    cI = tcI;
    cD = tcD;

    integralActiveZone = tintegralActiveZone;
    maxIntAdjust = tmaxIntAdjust;
}


int PIDObj::pidCalc(int desiredAngle, int angle){
    error = desiredAngle - angle; 

    int sumH = proportionalTerm() + integralTerm() + derivativeTerm();  

    lastError = error;
    
    if(sumH > 200){
        sumH = 200;
    }
    if(sumH < -200){
        sumH = -200;
    }

    if(error = 0){
        sumH = 0;
    }
    return sumH;
}

int PIDObj::proportionalTerm(){
	return error*cP;
}

//At this point, integral active zone is basically pseduo code. The point
//is to have a zone in which we'll bother adjusting.
int PIDObj::integralTerm(){
    if(error < (integralActiveZone)){
        errorS += error;
    }
    else{
        errorS = 0;
    }
    //MaxIntAdjust is another stand in. We don't want to increase
    //the integral term forever.
    if(errorS > maxIntAdjust){
        errorS = maxIntAdjust;
    }

    return errorS * cI;
}

int PIDObj::reachedTarget(){
    if(error == 0){
        return 1;
    }
    else return 0;
}

int PIDObj::derivativeTerm(){
	return (error -lastError)*cD;
}

int PIDObj::angleToServoUnit(int angle, int dMax, int dMin, int unitsPerCircle){
    int dCycle = (angle*(dMax - dMin + 1) + dMin*unitsPerCircle)/unitsPerCircle;
    return dCycle;
}
