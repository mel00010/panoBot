#include "PIDObj.hpp" 

double PIDObj::pidCalc(double desiredPos){

}

double PIDObj::proportionalTermH(){
	return errorH*cP;
}

//At this point, integral active zone is basically pseduo code. The point
//is to have a zone in which we'll bother adjusting.
double PIDObj::integralTermH(){
    if(errorH < (integralActiveZone)){
        errorSH += errorH;
    }
    else{
        errorSH = 0;
    }
    //MaxIntAdjust is another stand in. We don't want to increase
    //the integral term forever.
    if(errorSH > maxIntAdjust){
        errorSH = maxIntAdjust;
    }

    return errorSH * cI;
}

double PIDObj::derivativeTermH(){
	return (errorH -lastErrorH)*cD;
}
