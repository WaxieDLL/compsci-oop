#ifndef CFIRECALL_HPP
#define CFIRECALL_HPP

#include "../../interfaces/iemergencycall.hpp"

class CFireCall : public IEmergencyCall {
public:
	std::vector<EUnits> GetRelevantUnits() override {
		return { UNIT_AMBULANCE, UNIT_FIREDEPARTMENT };
	}
	void AssignUnit() override {
		//@TODO: Implement it
	}
	bool IsMedicalCall() override {
		return false;
	}
	bool IsBurglaryCall() override {
		return false;
	}
	bool IsFireCall() override {
		return true;
	}
	bool IsShootingCall() override {
		return false;
	}
};

#endif //CFIRECALL_HPP