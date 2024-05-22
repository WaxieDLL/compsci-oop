#ifndef CPOLICEUNIT_HPP
#define CPOLICEUNIT_HPP

#include "../../interfaces/idispatchableunit.hpp"

class CPoliceUnit : public IDispatchableUnit {
public:
	bool AssignCall(IEmergencyCall* pEmergencyCall) override;
	const std::vector<IEmergencyCall*> GetAssignedCalls() override;
	void DropCalls() override;

	

	bool IsPoliceUnit() override;
	bool IsMedicalUnit() override;
	bool IsFireUnit() override;
	static bool IsProperPoliceCall(IEmergencyCall* pEmergencyCall); // returns true if call is proper for police unit
private:
	std::vector<IEmergencyCall*> m_vecAssignedCalls{};
};

#endif //CPOLICEUNIT_HPP