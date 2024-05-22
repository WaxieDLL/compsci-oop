#include "cpoliceunit.hpp"
#include <algorithm>

bool CPoliceUnit::AssignCall(IEmergencyCall* pEmergencyCall)
{
	if (!pEmergencyCall)
		return false;

	if (!IsProperPoliceCall(pEmergencyCall))
		return false;

	m_vecAssignedCalls.push_back(pEmergencyCall);
	return true;
}

const std::vector<IEmergencyCall*> CPoliceUnit::GetAssignedCalls()
{
	return m_vecAssignedCalls;
}

void CPoliceUnit::DropCalls()
{
	m_vecAssignedCalls.clear();
}

bool CPoliceUnit::IsProperPoliceCall(IEmergencyCall* pEmergencyCall)
{
	const auto relevant_units = pEmergencyCall->GetRelevantUnits();
	return std::ranges::find(relevant_units, UNIT_POLICE) != relevant_units.end();
}

bool CPoliceUnit::IsPoliceUnit()
{
	return true;
}
bool CPoliceUnit::IsFireUnit()
{
	return false;
}
bool CPoliceUnit::IsMedicalUnit()
{
	return false;
}