#include "cfireunit.hpp"
#include <algorithm>

bool CFireUnit::AssignCall(IEmergencyCall* pEmergencyCall)
{
	if (!pEmergencyCall)
		return false;

	if (!IsProperFireCall(pEmergencyCall))
		return false;

	m_vecAssignedCalls.push_back(pEmergencyCall);
	return true;
}

const std::vector<IEmergencyCall*> CFireUnit::GetAssignedCalls()
{
	return m_vecAssignedCalls;
}

void CFireUnit::DropCalls()
{
	m_vecAssignedCalls.clear();
}

bool CFireUnit::IsProperFireCall(IEmergencyCall* pEmergencyCall)
{
	const auto relevant_units = pEmergencyCall->GetRelevantUnits();
	return std::ranges::find(relevant_units, UNIT_FIREDEPARTMENT) != relevant_units.end();
}

bool CFireUnit::IsPoliceUnit()
{
	return false;
}
bool CFireUnit::IsFireUnit()
{
	return true;
}
bool CFireUnit::IsMedicalUnit()
{
	return false;
}