#include "cmedicalunit.hpp"
#include <algorithm>

bool CMedicalUnit::AssignCall(IEmergencyCall* pEmergencyCall)
{
	if (!pEmergencyCall)
		return false;

	if (!IsProperMedicalCall(pEmergencyCall))
		return false;

	m_vecAssignedCalls.push_back(pEmergencyCall);
	return true;
}

const std::vector<IEmergencyCall*> CMedicalUnit::GetAssignedCalls()
{
	return m_vecAssignedCalls;
}

void CMedicalUnit::DropCalls()
{
	m_vecAssignedCalls.clear();
}

bool CMedicalUnit::IsProperMedicalCall(IEmergencyCall* pEmergencyCall)
{
	const auto relevant_units = pEmergencyCall->GetRelevantUnits();
	return std::ranges::find(relevant_units, UNIT_AMBULANCE) != relevant_units.end();
}

bool CMedicalUnit::IsPoliceUnit()
{
	return false;
}
bool CMedicalUnit::IsFireUnit()
{
	return false;
}
bool CMedicalUnit::IsMedicalUnit()
{
	return true;
}