#include "./Forms/AuthForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GeniusBooks::AuthForm authForm;

	Application::Run(% authForm);

	return 0;
}