#ifndef CMEDICALCALL_HPP
#define CMEDICALCALL_HPP

#include "../../interfaces/iemergencycall.hpp"

class CMedicalCall : public IEmergencyCall {
public:
	std::vector<EUnits> GetRelevantUnits() override {
		return { UNIT_AMBULANCE };
	}
	void AssignUnit() override {
		//@TODO: Implement it
	}
	bool IsMedicalCall() override {
		return true;
	}
	bool IsBurglaryCall() override {
		return false;
	}
	bool IsFireCall() override {
		return false;
	}
	bool IsShootingCall() override {
		return false;
	}
};

#endif //CMEDICALCALL_HPP