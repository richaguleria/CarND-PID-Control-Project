#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	p_error = 0;
	d_error = 0;
	i_error = 0;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
  	last_index = 0;
  	instancecount = 0; 
  	twidle = false;
	init = true;
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;

}

double PID::TotalError() {
	return (-Kp*p_error -Ki*i_error -Kd*d_error);
}

void PID::Twidle(double cte){
	// Minimise CTE
    double p[3] = {Kp,Ki,Kd};
    if((fabs(dp[0])+fabs(dp[1])+fabs(dp[2])) > 0.2)
    {
	    if(instancecount == 0)
	    {
	    	p[last_index] += dp[last_index];
	    	instancecount = 1;
	    }
	    else if(instancecount == 1)
	    {
	    	if(fabs(best_error) > fabs(cte))
	    	{
	    		best_error = cte;
	    		dp[last_index] *= 1.1;
	    		instancecount = 3;
	    	}
	    	else
	    	{
	    		p[last_index] -= 2*dp[last_index];
	    		instancecount = 2;
	    	}
	    }
	    else if(instancecount == 2)
	    {
	    	if(fabs(best_error) > fabs(cte))
	    	{
	    		best_error = cte;
	    		dp[last_index] *= 1.1;
	    		instancecount = 3;
	    	}
	    	else
	    	{
	    		p[last_index] += dp[last_index];
	    		dp[last_index] *= 0.9;
	    		instancecount = 3;
	    	}
	    }
	    else if(instancecount == 3)
	    {
	    	instancecount = 0;
	    	last_index = (last_index+1) % 3;
	    }
	    Kp = p[0];
	    Ki = p[1];
	    Kd = p[2];

	}
}