# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

Proportional(P) Component: The cross track error, cte is the current y position of the vehicle (our reference is a horizontal line) along the x-axis/trajectory. The steering angle, alpha, equals a proportional factor of tau_p to the cross track error.   

steering = -tau_p * crosstrack_error. This equation is P controller.

Differential(D) Component: When the steering angle equals a proportional factor of tau_p to the cross track error, car tends to overshoot. To avoid overshoot, PD controller is used. In PD controller,the steering angle should be set by the use of parameters tau_p and tau_d such that,

steering = -tau_p * CTE - tau_d * diff_CTE, where differential crosstrack error (diff_CTE) is given by CTE(t) - CTE(t-1)

Integral(I) Component: Incase there is systematic bias caused by few degrees of misalligment of vehicle tires, a large CTE is observed that prevents vehicle from reaching the centre line. In order to contain this error, I component is added to the PD controller that cancels out steering drift.

steering = -tau_p * CTE - tau_d * diff_CTE - tau_i * int_CTE where the integrated crosstrack error (int_CTE) is the sum of all the previous crosstrack errors.This term works to cancel out steering drift. This equation is PID controller.

Initial value set for tau_p , tau_d and tau_i is 0.1 , 1.5, 0 resp. using trial and error. tau_i is 0, considering no systematic bias as driving in simulated condition.

TWIDDLE is used to optimise average crosstrack error by tuning tau_p and tau_d parameters.

Further, initial value of throttle is set to 1.0. This value is brought to half if absolute cte exceeds 0.1 and speed exceeds 40.

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).



