#ifndef CFIREUNIT_HPP
#define CFIREUNIT_HPP

#include "../../interfaces/idispatchableunit.hpp"

class CFireUnit : public IDispatchableUnit {
public:
	bool AssignCall(IEmergencyCall* pEmergencyCall) override;
	const std::vector<IEmergencyCall*> GetAssignedCalls() override;
	void DropCalls() override;
	bool IsPoliceUnit() override;
	bool IsMedicalUnit() override;
	bool IsFireUnit() override;
	static bool IsProperFireCall(IEmergencyCall* pEmergencyCall); // returns true if call is proper for police unit
private:
	std::vector<IEmergencyCall*> m_vecAssignedCalls{};
};

#endif //CFIREUNIT_HPP