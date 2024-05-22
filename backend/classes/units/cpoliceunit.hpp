#ifndef CPOLICEUNIT_HPP
#define CPOLICEUNIT_HPP

#include "../../interfaces/idispatchableunit.hpp"

class CPoliceUnit : public IDispatchableUnit {
public:
	bool AssignCall(IEmergencyCall* pEmergencyCall) override;
	const std::vector<IEmergencyCall*> GetAssignedCalls() override;
	void DropCalls() override;
	static bool IsRelatedCall(IEmergencyCall* pEmergencyCall); // returns true if call is proper for police unit
private:
	std::vector<IEmergencyCall*> m_vecAssignedCalls{};
};

#endif //CPOLICEUNIT_HPP