#include "app.hpp"
#include "gui/window.hpp"
#include "widgets/widgets.hpp"

extern void HomeContent(CAppManager* app);
extern void DispatcherContent(CAppManager* app);

int main()
{
	CAppManager app;
	if (!app.IsValid())
		return -1;

	const auto pHomeWindow = app.AddWindow("Home Window");
	if (pHomeWindow.has_value())
		pHomeWindow.value()->SetCallback([&] {HomeContent(&app); });

	const auto pDispatchWindow = app.AddWindow("Dispatch Window");
	if (pDispatchWindow.has_value())
		pDispatchWindow.value()->SetCallback([&] {DispatcherContent(&app); });

	app.SetActiveWindow("Home Window");

	/* This also works!
	if(pHomeWindow.has_value())
		app.SetActiveWindow(pHomeWindow.value());
	*/

	app.MainLoop();
	return 0;
}

static void DrawNavbar(CAppManager* app) {
	std::string selected{};
	Widgets::Navbar("Police Station", { "Home", "Dispatch", "Officers", "Search" }, &selected);
	if (selected == "Home")
	{
		app->SetActiveWindow("Home Window");
	}
	else if (selected == "Dispatch")
	{
		app->SetActiveWindow("Dispatch Window");
	}
	else if (selected == "Officers")
	{
		app->SetActiveWindow("Home Window");
	}
	else if (selected == "Search")
	{
		app->SetActiveWindow("Home Window");
	}
}

void HomeContent(CAppManager* app)
{
	if (!app)
		return;

	DrawNavbar(app);

	ImGui::TextUnformatted("Home Window");
}
void DispatcherContent(CAppManager* app)
{
	if (!app)
		return;

	DrawNavbar(app);
	ImGui::TextUnformatted("Dispatch Window");
}