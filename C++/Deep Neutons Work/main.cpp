#include <iostream>
#include <algorithm>
#include <thread>
#include <future>
struct Activation
{
	constexpr static double Identity(double &input) {
		return input;
	}
	constexpr static double ReLu(double &input) {
		return std::max(0.0, input);
	}

};
class Neuron {
public:
	template <typename T>
	Neuron(T && Wight , T &&bias) :mWight(Wight), mBias(bias){
	}

	template <typename T>
	double feedForward(const double & input,T &fn) {
		double sigma = mWight * input + mBias;
		mOutput = fn(sigma);
		return mOutput;
	}
	void proBackWard(const double &target) {
		const double alpha = 0.1;
		const double grad = (mOutput - target) * getActgrad(mOutput);

		mWight -= alpha * grad * mInput;
		mBias -= alpha * grad * 1.0;
	}
	double getActgrad(const double &x) {
		return 1.0;
	}

protected:
	double mWight;
	double mBias;
	
	double mInput, mOutput;
};

int main() {
	Neuron a(2.0,1.0);



}