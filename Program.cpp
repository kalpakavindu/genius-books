#include "./Forms/AuthForm.h"
#include "Database.h";

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GeniusBooks::AuthForm authForm;

	Application::Run(% authForm);
}