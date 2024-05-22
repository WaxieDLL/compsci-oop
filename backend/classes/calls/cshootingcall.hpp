#ifndef CSHOOTINGCALL_HPP
#define CSHOOTINGCALL_HPP

#include "../../interfaces/iemergencycall.hpp"

class CShootingCall : public IEmergencyCall {
public:
	std::vector<EUnits> GetRelevantUnits() override {
		return { UNIT_AMBULANCE, UNIT_POLICE };
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
		return false;
	}
	bool IsShootingCall() override {
		return true;
	}
};

#endif //CSHOOTINGCALL_HPP