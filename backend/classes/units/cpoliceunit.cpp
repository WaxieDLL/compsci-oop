#include "cpoliceunit.hpp"
#include <algorithm>

bool CPoliceUnit::AssignCall(IEmergencyCall* pEmergencyCall) override
{
	if (!pEmergencyCall)
		return false;

	if (!IsRelatedCall(pEmergencyCall))
		return false;

	m_vecAssignedCalls.push_back(pEmergencyCall);
	return true;
}

const std::vector<IEmergencyCall*> CPoliceUnit::GetAssignedCalls() override
{
	return m_vecAssignedCalls;
}

void CPoliceUnit::DropCalls() override
{
	m_vecAssignedCalls.clear();
}

bool CPoliceUnit::IsRelatedCall(IEmergencyCall* pEmergencyCall)
{
	const auto relevant_units = pEmergencyCall->GetRelevantUnits();
	return std::ranges::find(relevant_units, UNIT_POLICE) != relevant_units.end();
}