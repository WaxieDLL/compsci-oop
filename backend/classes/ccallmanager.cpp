#include "ccallmanager.hpp"
#include "../interfaces/iemergencycall.hpp"
#include "../classes/calls/cshootingcall.hpp"
#include "../classes/calls/cburglarycall.hpp"
#include "../classes/calls/cmedicalcall.hpp"
#include "../classes/calls/cfirecall.hpp"
#include "../enums/eincidents.hpp"

std::shared_ptr<IEmergencyCall> CCallManager::CreateEmergencyCall(const std::string& incident)
{
	std::shared_ptr<IEmergencyCall> call;
	if (incident == "Medical")
		call = std::shared_ptr<IEmergencyCall>(CreateMedicalCall());
	else if (incident == "Burglary")
		call = std::shared_ptr<IEmergencyCall>(CreateBurglaryCall());
	else if (incident == "Fire")
		call = std::shared_ptr<IEmergencyCall>(CreateFireCall());
	else if (incident == "Shooting")
		call = std::shared_ptr<IEmergencyCall>(CreateShootingCall());
	else
		return nullptr;

	m_vecCalls.push_back(call);
	return call;
}

CMedicalCall* CCallManager::CreateMedicalCall()
{
	return new CMedicalCall;
}

CBurglaryCall* CCallManager::CreateBurglaryCall()
{
	return new CBurglaryCall;
}

CFireCall* CCallManager::CreateFireCall()
{
	return new CFireCall;
}

CShootingCall* CCallManager::CreateShootingCall()
{
	return new CShootingCall;
}
