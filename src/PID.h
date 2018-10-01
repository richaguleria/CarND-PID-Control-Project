#ifndef PID_H
#define PID_H
#include <iostream>
#include<cmath>
class PID {

public:
  
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  /*
  * Coefficients
  */ 

  double Kp;
  double Ki;
  double Kd;
  /* 
  * Variables 
  */
  double dp[3];

  double best_error;
  int last_index ;
  int instancecount ; 
  bool twidle;
  bool init = false;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);
  /*
  * Optimise coefficients
  */
  void Twidle(double cte);
  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};
#endif /* PID_H */
