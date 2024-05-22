#ifndef CMEDICALUNIT_HPP
#define CMEDICALUNIT_HPP

#include "../../interfaces/idispatchableunit.hpp"

class CMedicalUnit : public IDispatchableUnit {
public:
	bool AssignCall(IEmergencyCall* pEmergencyCall) override;
	const std::vector<IEmergencyCall*> GetAssignedCalls() override;
	void DropCalls() override;
	bool IsPoliceUnit() override;
	bool IsMedicalUnit() override;
	bool IsFireUnit() override;
	static bool IsProperMedicalCall(IEmergencyCall* pEmergencyCall);
private:
	std::vector<IEmergencyCall*> m_vecAssignedCalls{};
};

#endif //CMEDICALUNIT_HPP