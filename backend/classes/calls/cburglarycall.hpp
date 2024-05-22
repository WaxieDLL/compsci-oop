#ifndef CBURGLARYCALL_HPP
#define CBURGLARYCALL_HPP

#include "../../interfaces/iemergencycall.hpp"

class CBurglaryCall : public IEmergencyCall {
public:
	std::vector<EUnits> GetRelevantUnits() override {
		return { UNIT_POLICE };
	}
	void AssignUnit() override {
		//@TODO: Implement it
	}
	bool IsMedicalCall() override {
		return false;
	}
	bool IsBurglaryCall() override {
		return true;
	}
	bool IsFireCall() override {
		return false;
	}
	bool IsShootingCall() override {
		return false;
	}
};

#endif //CBURGLARYCALL_HPP